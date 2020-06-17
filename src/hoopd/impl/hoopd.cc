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
HttpServer& HttpServer::set_scope(const std::string& scope) {
    _scope = scope;
    return *this;
}

HttpServer& HttpServer::get(const std::string& pattern, Handler h) {
    _gets.push_back(std::make_pair(std::regex(pattern), h));
    return *this;

    // true if rgx is matched against the target sequence. false otherwise.
    // std::string s ("/api/get");
    // std::regex e ("/api/");
    // std::cout << std::regex_match (s,e) << std::endl;
}

} // namespace hoopd
