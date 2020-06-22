#include <iostream>
#include <hoopd/hoopd.h>

using namespace hoopd;

class Echo {
public:
    std::string echo() {
        std::string body{"Hi there; my name is hoopd, Good to see you."};
        return body;
    }
};

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

    server.get("/echo", [](const Request& req, Response& res) {
        Echo e;
        std::string message = e.echo();

        std::string k{"Cache-control"};
        std::string v{"no-cache"};
        res.set_header(k, v);
        res.set_body(message);
    });

    server.run();
}
