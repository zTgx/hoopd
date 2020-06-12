#include <hoopd/settings.h>
#include <hoopd/nocopyable.h>

namespace hoopd {
class HttpServer : public noncopyable {
public:
    explicit HttpServer();
    explicit HttpServer(const Settings&);
    virtual ~HttpServer();

public:
    virtual bool run();

private:
    Settings _settings; // default settings
// ------------------------------------
public:
    //test cases
    std::string getHost() {
        return _settings.host;
    }
};
}