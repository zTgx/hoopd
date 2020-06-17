#include <hoopd/response.h>
#include <iostream>

namespace hoopd {
const void Response::description() const {
    std::cout << "Response description..." << std::endl;
}
}
