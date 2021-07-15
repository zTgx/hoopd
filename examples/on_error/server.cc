#include <iostream>
#include <hoopd.h>

using namespace hoopd;

int main() {
    Hoopd server;

    server.on_error([](const http::Request& req, http::Response& res) {
        req.description();
        res.description();
        
        std::string body{"ERROR: WRONG REQUEST"};
        res.body = body;
    });

    server.run();
}
