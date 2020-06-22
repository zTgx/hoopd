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

void Response::set_header(const std::string& key, const std::string& value) {
    _http_header.add_entity(key, value);
}
void Response::set_body(std::string& body) {
    _body = body;
}
const HttpHeader Response::get_header() const {
    return _http_header;
}
const std::string Response::get_body() const {
    return _body;
}

}
