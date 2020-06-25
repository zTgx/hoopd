#include <iostream>
#include <hoopd/hoopd.h>

using namespace hoopd;

int main() {
    HttpServer server;

    server.on_error([](const Request& req, Response& res) {
        req.description();
        res.description();
        
        std::string body{"ERROR: WRONG REQUEST"};
        res.body = body;
    });

    server.run();
}
