#ifndef __HOOPD_INTERNAL_HANDLER_H_
#define __HOOPD_INTERNAL_HANDLER_H_

#include <iostream>
#include <functional> //std::function
#include <hoopd/request.h>
#include <hoopd/response.h>
#include <regex> // std::regex

namespace hoopd {
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