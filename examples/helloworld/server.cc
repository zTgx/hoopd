#include <iostream>
#include <hoopd.h>

using namespace hoopd;

int main() {
    Hoopd server;
    server.set_scope("/api/v2");

    server.get("/hi", [](const http::Request& req, http::Response& res) {
        std::string message{"Hi there; my name is hoopd, Good to see you."};

        std::string k{"Cache-control"};
        std::string v{"no-cache"};
        res.header.headers(k, v);
        
        res.body = message;
    });

    server.run();
}
