
#include <hoopd/internal/nocopyable.h>
#include <hoopd/settings.h>
#include <hoopd/internal/service.h>
#include <hoopd/internal/handler.h>

namespace hoopd {
class HttpServer : public noncopyable {
public:
    explicit HttpServer();
    explicit HttpServer(const Settings&);
    virtual ~HttpServer();

public:
    virtual bool run();

private:
    std::string _scope;

public:
    HttpServer& set_scope(const std::string&);
    HttpServer& get(const std::string&, Handler::Action);

private:
    Settings _settings;
    Service _service;
    Handler _handler;
};
}