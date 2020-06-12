#include <hoopd/hoopd.h>
#include <iostream>

namespace hoopd
{
HttpServer::HttpServer() : noncopyable() {
}

HttpServer::HttpServer(const Settings& settings) : noncopyable() {
    _settings = settings;
}

HttpServer::~HttpServer() {
}

bool HttpServer::run() {
    std::cout << "hoopd is started running ... " << std::endl;

    return true;
}

// ---------------------------
void HttpServer::set_scope(const std::string&) {
}

void HttpServer::get(const std::string&, Handler) {
}

} // namespace hoopd
