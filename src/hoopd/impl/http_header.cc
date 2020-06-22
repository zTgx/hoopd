#include <hoopd/internal/http_header.h>

namespace hoopd {
void HttpHeader::add_entity(const std::string& key, const std::string &val) {
    _headers.emplace(key, val);
}

HttpHeader::Headers HttpHeader::get_headers() const {
    return _headers;
}
}