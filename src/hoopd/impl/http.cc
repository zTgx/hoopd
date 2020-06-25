#include <sstream>

#include <hoopd/http.h>

namespace hoopd {

using namespace http;

void HttpHeader::add_entity(const std::string& key, const std::string &val) {
    _headers.emplace(key, val);
}
void HttpHeader::set_params(const Params& p) {
    _params = p;
}
HttpHeader::Headers HttpHeader::get_headers() const {
    return _headers;
}
HttpHeader::Params HttpHeader::get_params() const {
    return _params;
}

std::string HttpHeader::data() const {
    std::stringstream stream;
    for(auto entity : _headers) {
        auto key   = entity.first;
        auto value = entity.second;

        stream << key << ":" << value << "\r\n";
    }

    return stream.str();
}

///////////////////////////////////////////////////////////

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

//////////////////////////////////////////////////////////////
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