#include <iostream>
#include <hoopd/hoopd.h>

using namespace hoopd;

int main() {
    // hoopd::Settings defaultSettings;
    // hoopd::HttpServer server(defaultSettings);

    HttpServer server;
    server.set_scope("/api/v2");

    server.get("/server-info", [](const Request& req, Response& res) {
        std::cout << "\n################# logic callback ###################" << std::endl;
        req.description();
        res.description();
    });

    class Echo {
    public:
        void echo() {
            std::cout << "fixed echo." << std::endl;
        }
    };
    server.get("/echo", [](const Request& req, Response& res) {
        Echo e;
        e.echo();
    });

    server.run();
}
