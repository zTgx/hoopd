#include <hoopd/request.h>
#include <iostream>

namespace hoopd {
const void Request::description() const {
    std::cout << "Request description ..." << std::endl;
}
}