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

bool HttpServer::is_running() const {
    return true;
}

bool HttpServer::stop() {
    return true;
}

bool HttpServer::run() {
    std::cout << "hoopd is started running on " << _settings.host << ":" << _settings.port << std::endl;

    _service.set_handler(_handler);
    _service.set_settings(_settings);
    
    return _service.run();
}

HttpServer& HttpServer::set_scope(const std::string& scope) {
    _scope = scope;
    return *this;
}

HttpServer& HttpServer::get(const std::string& pattern, Handler::Action h) {
    _handler.push_back(_scope + pattern, h);
    return *this;
}

HttpServer& HttpServer::on_error(Handler::Action h) {
    _handler.push_error(h);
    return *this;
}
} // namespace hoopd
