#ifndef __HOOPD_INTERNAL_HANDLER_H_
#define __HOOPD_INTERNAL_HANDLER_H_

#include <iostream>
#include <functional> //std::function
#include <regex> // std::regex

#include <hoopd/http.h>

namespace hoopd {
using namespace http;

class Handler {    
public:
    typedef std::function<void(const Request&, Response&)> Action;
    typedef std::vector<std::pair<std::regex, Action>> Routers;

public:
    Action handle(const std::string&);
    void push_back(const std::string&, Action);
    void push_error(Action h);

private:
    Routers _gets;
    Action _on_error;
};
} // namespace hoopd

#endif