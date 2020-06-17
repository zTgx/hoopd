#ifndef __HOOPD_SETTINGS_H_
#define __HOOPD_SETTINGS_H_

#include <string>

namespace hoopd {
struct Settings {
    std::string host = "localhost";
    size_t      port = 9527;
};
}

#endif