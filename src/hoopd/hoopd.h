#include <hoopd/settings.h>
#include <hoopd/nocopyable.h>

namespace hoopd {
class HttpServer : public noncopyable {
public:
    // Constructor
    explicit HttpServer(const Settings&);

    // Destructor
    virtual ~HttpServer();

public:
    // HttpServer run 
    virtual bool run();
};
}