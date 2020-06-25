#include <hoopd/request.h>
#include <iostream>

namespace hoopd {
Request::Request() {}
Request::Request(const http::Message& message) {
    // Headers
    for(auto i=0;i<message.fields.size();i++) {
        std::string field = message.fields[i];
        std::string value = message.values[i];

        _http_header.add_entity(field.c_str(), value);
    }

    // Params
    _http_header.set_params(message.params);

    // Path
    path = message.path;

    // Version
    // version = message.version;

    // Method
    // method = http_method(message.method);

    // Body
    body = message.body;
}

Request::~Request() {
}

const void Request::description() const {
    std::cout << "################# Request description ..." << std::endl;

    for(auto x : _http_header.get_headers()) {
        std::cout << x.first << ":" << x.second << std::endl;
    }

    for(auto x : _http_header.get_params()) {
        std::cout << x.first << ":" << x.second << std::endl;
    }
}
}