#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>	//inet_addr

#include <hoopd/internal/service.h>
#include <iostream>

#define MAX_EVENTS 10

namespace hoopd {
void Service::set_settings(const Settings& settings) {
    _settings = settings;
}

bool Service::run() {
    int socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1){
		printf("Could not create socket");
	}

    // bind 
    struct sockaddr_in server;

    const char* host = _settings.host.c_str();
    size_t port = _settings.port;
    
	server.sin_addr.s_addr = inet_addr(host);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
	{
		//print the error message
		perror("bind failed. Error");
		return 1;
	}
	std::cout << "bind done" << std::endl;

    listen(socket_desc, 3);

    std::cout << "listening on: " << _settings.host << ":" << _settings.port << std::endl;

    struct epoll_event ev, events[MAX_EVENTS];
    int listen_sock, conn_sock, nfds, epollfd;

    /* Code to set up listening socket, 'listen_sock',
        (socket(), bind(), listen()) omitted */

    std::cout << "epoll create 1" << std::endl;

    epollfd = epoll_create1(0);
    std::cout << "epollfd : " << epollfd << std::endl;

    if (epollfd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    ev.events = EPOLLIN;
    ev.data.fd = listen_sock;
    if (epoll_ctl(epollfd, EPOLL_CTL_ADD, listen_sock, &ev) == -1) {
        perror("epoll_ctl: listen_sock");
        exit(EXIT_FAILURE);
    }

    std::cout << "while(true)" << std::endl;

    while (true) {
        std::cout << "start await ..." << std::endl;

        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
        std::cout << "nfds: " << nfds << std::endl;

        if (nfds == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (int n = 0; n < nfds; ++n) {
            if (events[n].data.fd == listen_sock) {
                struct sockaddr addr;
                socklen_t addrlen;

                conn_sock = accept(listen_sock, (struct sockaddr *) &addr, &addrlen);
                if (conn_sock == -1) {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }

                // setnonblocking(conn_sock);

                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
                    perror("epoll_ctl: conn_sock");
                    exit(EXIT_FAILURE);
                }
            } else {
                // do_use_fd(events[n].data.fd);
                std::cout << "do use fd = " << events[n].data.fd << std::endl;
            }
        }
    }

    return true;
}
}