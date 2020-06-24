#include <hoopd/internal/handler.h>

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
}