#ifndef __HOOPD_INTERNAL_HTTPHEADER_H_
#define __HOOPD_INTERNAL_HTTPHEADER_H_

#include <iostream>
#include <unordered_map>
#include <hoopd/3rd/json/json.hpp>

namespace hoopd {

enum class Method {
    GET,
    POST,
    PUT,
    DELETE,
    UPDATE,
};

enum class HttpVersion {
    v1_0 = 0, 
    v1_1,
    V2_0 
};

class HttpHeader {
public:
    typedef std::unordered_map<std::string, std::string> Headers;

public:
    void add_entity(const char *key, const char *val);
    void add_entity(const char *key, const std::string &val);

    std::string get_header_value(const char *key) const;

private:
    Headers _headers;
};
 
}

#endif
