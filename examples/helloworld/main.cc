#include <iostream>
#include <hoopd/hoopd.h>

int main() {
    // hoopd::Settings defaultSettings;
    // hoopd::HttpServer server(defaultSettings);

    hoopd::HttpServer server;
    std::cout << "host: " << server.getHost() << std::endl;
    server.run();
}
