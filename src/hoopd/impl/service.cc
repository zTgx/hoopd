#include <hoopd/internal/service.h>

namespace hoopd {
void Service::set_settings(const Settings& settings) {
    _settings = settings;
}

bool Service::run() {
    return true;
}
}