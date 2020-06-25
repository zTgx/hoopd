#include <iostream>
#include <hoopd/hoopd.h>

using namespace hoopd;

int main() {
    HttpServer server;
    server.set_scope("/api/v2");

    server.get("/get", [](const Request& req, Response& res) {
        req.description();
        
        std::string message{"Hi there; my name is hoopd, Good to see you."};

        std::string k{"Cache-control"};
        std::string v{"no-cache"};
        res.set_header(k, v);
        
        res.set_body(message);
    });

    server.on_error([](const Request& req, Response& res) {
        req.description();
        std::cout << req.path << std::endl;

        std::string body{"ERROR: WRONG REQUEST"};
        res.set_body(body);
    });

    server.run();
}
