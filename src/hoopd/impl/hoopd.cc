#include <hoopd/hoopd.h>
#include <iostream>

namespace hoopd
{
HttpServer::HttpServer(const Settings& settings) {
}

HttpServer::~HttpServer() {
}

bool HttpServer::run() {
    std::cout << "hoopd is started running ... " << std::endl;

    return true;
}
} // namespace hoopd
