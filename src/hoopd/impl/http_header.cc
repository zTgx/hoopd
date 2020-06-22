#include <hoopd/internal/http_header.h>
#include <sstream>

namespace hoopd {
void HttpHeader::add_entity(const std::string& key, const std::string &val) {
    _headers.emplace(key, val);
}

HttpHeader::Headers HttpHeader::get_headers() const {
    return _headers;
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