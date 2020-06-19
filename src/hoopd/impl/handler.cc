#include <hoopd/internal/handler.h>

namespace hoopd {
void Handler::handle(const std::string& pattern) {
    std::cout << "handler pattern: " << pattern << std::endl;
    for(auto x : _gets) {
        std::regex reg = x.first;
        if(std::regex_match(pattern, reg)) {
            Action h = x.second;

            Request req;
            Response res;

            std::cout << "pattern equal" << std::endl;

            h(req, res);
        }
    }
}
void Handler::push_back(const std::string& pattern, Action h) {
    std::cout << "push pattern : " << pattern << std::endl;
    _gets.push_back(std::make_pair(std::regex(pattern), h));
}
}