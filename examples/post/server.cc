#include <iostream>
#include <hoopd/hoopd.h>

using namespace hoopd;

int main() {
    HttpServer server;

    server.set_scope("/api/v2");
    server.post("/post", [](const http::Request& req, http::Response& res) {
        req.description();
        res.description();
        
        std::string post_body = req.body;

        res.body = post_body;
    });

    server.run();
}
