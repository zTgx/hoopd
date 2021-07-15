#include <iostream>

#include <hoopd.h>
#include <internal/parser.h>
#include <internal/stream.h>

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

// #define MAX_EVENTS 1024
// #define HOOPD_RECV_BUFSIZ size_t(4096u)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
namespace hoopd {
Handler::Action Handler::handle(const std::string& pattern) {
    for(auto x : _gets) {
        std::regex reg = x.first;
        if(std::regex_match(pattern, reg)) {
            return x.second;
        }
    }

    return _on_error;
}
void Handler::push_back(const std::string& pattern, Action h) {
    _gets.push_back(std::make_pair(std::regex(pattern), h));
}
void Handler::push_error(Action h) {
    _on_error = h;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Hoopd::Hoopd() : noncopyable() {
}

Hoopd::Hoopd(const http::Settings& settings) : noncopyable() {
    _settings = settings;
}

Hoopd::~Hoopd() {
}

bool Hoopd::is_running() const {
    return true;
}

bool Hoopd::stop() {
    return true;
}

bool Hoopd::run() {
    print_lanuch_mascot();

    std::cout << "hoopd is started running on " << _settings.host << ":" << _settings.port << std::endl;

    _service.set_handler(_handler);
    _service.set_settings(_settings);
    
    return _service.run();
}

Hoopd& Hoopd::set_scope(const std::string& scope) {
    _scope = scope;
    return *this;
}

Hoopd& Hoopd::get(const std::string& pattern, Handler::Action h) {
    _handler.push_back(_scope + pattern, h);
    return *this;
}
Hoopd& Hoopd::post(const std::string& pattern, Handler::Action h) {
    _handler.push_back(_scope + pattern, h);
    return *this;
}
Hoopd& Hoopd::on_error(Handler::Action h) {
    _handler.push_error(h);
    return *this;
}
} // namespace hoopd
