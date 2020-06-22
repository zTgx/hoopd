#include <hoopd/internal/http_header.h>

namespace hoopd {
void HttpHeader::add_entity(const char *key, const char *val) {
    _headers.emplace(key, val);
}

void HttpHeader::add_entity(const char *key, const std::string &val) {
    _headers.emplace(key, val);
}

std::string HttpHeader::get_header_value(const char *key) const {
    return _headers.at(key);
}

}