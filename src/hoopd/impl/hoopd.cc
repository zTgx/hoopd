#include <hoopd/hoopd.h>
#include <iostream>

static void print_lanuch_mascot() {
    std::string ascii_name = R"(
ooooo ooooo  ooooooo     ooooooo  oooooooooo ooooooooo   
 888   888 o888   888o o888   888o 888    888 888    88o 
 888ooo888 888     888 888     888 888oooo88  888    888 
 888   888 888o   o888 888o   o888 888        888    888 
o888o o888o  88ooo88     88ooo88  o888o      o888ooo88   
)";
    std::cout << ascii_name << std::endl;
}  

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
    print_lanuch_mascot();

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
