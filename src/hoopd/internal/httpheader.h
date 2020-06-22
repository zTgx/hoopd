#ifndef __HOOPD_INTERNAL_HTTPHEADER_H_
#define __HOOPD_INTERNAL_HTTPHEADER_H_

#include <unordered_map>

#include <hoopd/3rd/json/json.hpp>

// for convenience
using json = nlohmann::json;

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

typedef std::unordered_map<std::string, std::string> Headers;

// void to_json(json& j, const Request& p) {
//     j = json{{"image_path", p.image_path}};
// }

// void from_json(const json& j, Request& p) {
//     j.at("image_path").get_to(p.image_path);
// }
 
}

#endif
