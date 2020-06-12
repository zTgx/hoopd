#include <hoopd/hoopd.h>
#include <iostream>

namespace hoopd
{
HttpServer::HttpServer() {
}

HttpServer::~HttpServer() {
}

bool HttpServer::run() {
    std::cout << "hoopd is started running ... " << std::endl;

    return true;
}
} // namespace hoopd
