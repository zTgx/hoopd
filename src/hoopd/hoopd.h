#include <functional> //std::function
#include <hoopd/nocopyable.h>
#include <hoopd/settings.h>
#include <hoopd/service.h>
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

public:
    void set_scope(const std::string&);
    void get(const std::string&, Handler);

private:
    Settings _settings;
    Service service;
};
}