#ifndef __HOOPD_INTERNAL_HTTPHEADER_H_
#define __HOOPD_INTERNAL_HTTPHEADER_H_

#include <unordered_map>


namespace hoopd {
enum class Method {
    GET,
    POST,
    PUT,
    DELETE,
    UPDATE,
};

typedef std::unordered_map<std::string, std::string> Headers;

}

#endif
