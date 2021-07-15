#include <sys/epoll.h>
#include <arpa/inet.h>	//inet_addr
#include <sys/socket.h>
#include <fcntl.h>

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <hoopd.h>

#include <internal/parser.h>
#include <internal/stream.h>

#define MAX_EVENTS 1024
#define HOOPD_RECV_BUFSIZ size_t(4096u)

namespace hoopd {
void Service::set_handler(Handler& h) {
    _handler = h;
}

void Service::set_settings(const http::Settings& settings) {
    _settings = settings;
}

bool Service::run() {
    struct epoll_event ev, events[MAX_EVENTS];
    int listen_sock, conn_sock, nfds, epollfd;
    struct sockaddr_in address;    
    
    // Creating socket file descriptor
    if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("In socket");
        exit(EXIT_FAILURE);
    }

    size_t port = _settings.port;

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    
    memset(address.sin_zero, '\0', sizeof address.sin_zero);
    
    if (bind(listen_sock, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("In bind");
        exit(EXIT_FAILURE);
    }
    if (listen(listen_sock, 10) < 0)
    {
        perror("In listen");
        exit(EXIT_FAILURE);
    }

    epollfd = epoll_create1(0);
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

    while(1) {
        printf("\n+++++++ Waiting for new connection ++++++++\n\n");

        nfds = epoll_wait(epollfd, events, MAX_EVENTS, -1);
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

                set_nonblocking(conn_sock, true);

                ev.events = EPOLLIN | EPOLLET;
                ev.data.fd = conn_sock;
                if (epoll_ctl(epollfd, EPOLL_CTL_ADD, conn_sock, &ev) == -1) {
                    perror("epoll_ctl: conn_sock");
                    exit(EXIT_FAILURE);
                }
            } else {
                int fd  = events[n].data.fd;
                handle_request(fd);
            }
        }
    }

    return 0;
}

void Service::set_nonblocking(int sock, bool nonblocking) {
    auto flags = fcntl(sock, F_GETFL, 0);
    fcntl(sock, F_SETFL, nonblocking ? (flags | O_NONBLOCK) : (flags & (~O_NONBLOCK)));
}

void Service::handle_request(int fd) {
    char buffer[HOOPD_RECV_BUFSIZ] = {0};
    long valread = recv(fd, buffer, HOOPD_RECV_BUFSIZ, 0);

    http::HttpParser parser;
    http::Message message = parser.parse(buffer, valread);

    http::Request req{message};
    http::Response res{};

    Handler::Action h = _handler.handle(req.header.path());
    h(req, res);    

    // Use Scope
    {
        Stream s{fd};

        const char* http_status = "HTTP/1.1 200 OK\n";
        s << http_status;
        
        std::string header = res.header.data();
        s << header;
        s << "\n\n"; // \n\n indicates http header data is over.

        s << res.body;
        s << "\r\n";

        s.send();
    }

    close(fd);
}

}