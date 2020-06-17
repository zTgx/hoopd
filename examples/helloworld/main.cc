#include <iostream>
#include <hoopd/hoopd.h>

using namespace hoopd;

int main() {
    // hoopd::Settings defaultSettings;
    // hoopd::HttpServer server(defaultSettings);

    HttpServer server;
    server.set_scope("api/v2");

    server.get("/server-info", [](const Request& req, Response& res) {
        std::cout << "req description : " << req.description() << std::endl;
        std::cout << "res description : " << res.description() << std::endl;
    });

    server.run();
}
