#include <iostream>
#include <hoopd.h>

using namespace hoopd;

int main() {
    hoopd::Settings defaultSettings;
    hoopd::Hoopd server(defaultSettings);

    server.set_scope("/api/v2");

    server.get("/echo", [](const Request& req, Response& res) {        
        std::string message = req.body;

        std::string k{"Cache-control"};
        std::string v{"no-cache"};
        res.set_header(k, v);
        res.set_body(message);
    });

    server.run();
}
