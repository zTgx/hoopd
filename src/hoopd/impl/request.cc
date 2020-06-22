#include <hoopd/request.h>
#include <iostream>

namespace hoopd {
Request::Request() {

}
Request::Request(const http::Message& message) {
    
}

Request::~Request() {

}

const void Request::description() const {
    std::cout << "Request description ..." << std::endl;
}
}