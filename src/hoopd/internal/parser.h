#ifndef _HOOPD_INTERNAL_PARSER_H_
#define _HOOPD_INTERNAL_PARSER_H_

#include <iostream>
#include <hoopd/3rd/httpparser/http_parser.h>
#include <hoopd/internal/nocopyable.h>
#include <hoopd/internal/handler.h>

#include <cassert>

// #include <hoopd/3rd/json/json.hpp>

// // for convenience
// using json = nlohmann::json;

// namespace ns {
//     struct Body {
//         std::string image_path;
//     };

//     void to_json(json& j, const Body& p) {
//         j = json{{"image_path", p.image_path}};
//     }

//     void from_json(const json& j, Body& p) {
//         j.at("image_path").get_to(p.image_path);
//     }
// } // namespace ns

namespace hoopd {
namespace http {
class HttpParser : public noncopyable {
public:
    void parse(const char*, long, Handler&);

};

static int on_message_begin(http_parser *p);
static int on_url(http_parser* p, const char *at, size_t length);
static int on_status(http_parser* p, const char *at, size_t length);
static int on_header_field(http_parser* p, const char *at, size_t length);
static int on_header_value(http_parser* p, const char *at, size_t length);
static int on_body(http_parser* p, const char *at, size_t length);
}
}

#endif