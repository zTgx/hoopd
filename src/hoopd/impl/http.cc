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

}