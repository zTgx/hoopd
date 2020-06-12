#include <hoopd/settings.h>
#include <hoopd/nocopyable.h>

namespace hoopd {
class HttpServer : public noncopyable {
public:
    explicit HttpServer(const Settings&);
    virtual ~HttpServer();

public:
    virtual bool run();
};
}