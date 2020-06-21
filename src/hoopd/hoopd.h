// internal headers
#include <hoopd/internal/nocopyable.h>
#include <hoopd/internal/service.h>
#include <hoopd/internal/handler.h>

// public headers
#include <hoopd/settings.h>

namespace hoopd {
class HttpServer : public noncopyable {
public:
    explicit HttpServer();
    explicit HttpServer(const Settings&);
    virtual ~HttpServer();

public:
    virtual bool run();

public:
    HttpServer& set_scope(const std::string&);
    HttpServer& get(const std::string&, Handler::Action);

private:
    std::string _scope;

private:
    Settings _settings;
    Service _service;
    Handler _handler;
};
}