#include <sstream>

#include <hoopd/http.h>

namespace hoopd {

using namespace http;

/////////////////////////////////////////////////////////////////////////////////////
HttpHeader::Headers HttpHeader::headers() const {
    return _headers;
}
void HttpHeader::headers(const std::string& key, const std::string &val) {
    _headers.emplace(key, val);
}
HttpHeader::Params HttpHeader::params() const {
    return _params;
}
void HttpHeader::params(const Params& p) {
    _params = p;
}
std::string HttpHeader::version() const {
    return _version;
}
void HttpHeader::version(const std::string& version) {
    _version = version;
}
std::string HttpHeader::method() const {
    return _method;
}
void HttpHeader::method(const std::string& method) {
    _method = method;
}
std::string HttpHeader::path() const {
    return _path;
}
void HttpHeader::path(const std::string& path) {
    _path = path;
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

//////////////////////////////////////////////////////////////
Request::Request() {}
Request::Request(const http::Message& message) {
    // Headers
    for(auto i=0;i<message.fields.size();i++) {
        std::string field = message.fields[i];
        std::string value = message.values[i];

        header.headers(field.c_str(), value);
    }

    // Params
    header.params(message.params);

    // Path
    header.path(message.path);

    // Version
    header.version(message.version);

    // Method
    header.method(message.method);

    // Body
    body = message.body;
}

Request::~Request() {
}

const void Request::description() const {
    std::cout << "################# Request description ..." << std::endl;

    for(auto x : header.headers()) {
        std::cout << x.first << ":" << x.second << std::endl;
    }

    for(auto x : header.params()) {
        std::cout << x.first << ":" << x.second << std::endl;
    }
}


///////////////////////////////////////////////////////////

Response::Response() {
}
Response::~Response() {
}
const void Response::description() const {
    std::cout << "Response description..." << std::endl;
}
}