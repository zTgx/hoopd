#include <hoopd/response.h>
#include <iostream>

namespace hoopd {
Response::Response() {

}

Response::~Response() {

}
const void Response::description() const {
    std::cout << "Response description..." << std::endl;
}
}
