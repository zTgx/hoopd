#ifndef __HOOPD_INTERNAL_SERVICE_H_
#define __HOOPD_INTERNAL_SERVICE_H_

#include <hoopd/settings.h>

namespace hoopd {
class Service {
public:
    void set_settings(const Settings&);
    bool run();

private:
    void handle_request(int);
    
private:
    Settings _settings;
};
}

#endif