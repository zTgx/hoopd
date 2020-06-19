#include <functional> //std::function
#include <regex> // std::regex

#include <hoopd/internal/nocopyable.h>
#include <hoopd/settings.h>
#include <hoopd/internal/service.h>
#include <hoopd/request.h>
#include <hoopd/response.h>

namespace hoopd {
class HttpServer : public noncopyable {
public:
    explicit HttpServer();
    explicit HttpServer(const Settings&);
    virtual ~HttpServer();

public:
    virtual bool run();

public:
    typedef std::function<void(const Request&, Response&)> Handler;
    typedef std::vector<std::pair<std::regex, Handler>> Routers;

private:
    std::string _scope;
    Routers _gets;

public:
    HttpServer& set_scope(const std::string&);
    HttpServer& get(const std::string&, Handler);

    void handle_gets(const std::string&);

private:
    Settings _settings;
    Service _service;
};
}