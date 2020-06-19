#include <hoopd/internal/parser.h>

#include <hoopd/3rd/json/json.hpp>
// for convenience
using json = nlohmann::json;

// namespace hoopd {
// template <typename T>
// void Parser::parse() {

// } 
// }

namespace hoopd {
namespace parser {
void HttpParser::parse(const char* buffer, long data_len, Handler& h) {
    http_parser_settings settings = {
        .on_message_begin       = on_message_begin,
        .on_url                 = on_url,
        .on_status              = on_status,
        .on_header_field        = on_header_field,
        .on_header_value        = on_header_value,
        // .on_headers_complete    = on_info,
        .on_body                = on_body,
        // .on_message_complete    = on_info,        
    };
    struct http_parser parser;

    size_t parsed;
    http_parser_init(&parser, HTTP_REQUEST);

    parsed = http_parser_execute(&parser, &settings, buffer, data_len);
    std::cout << "parsed: " << parsed << std::endl;

    std::string method{http_method_str((enum http_method)parser.method)};
    std::cout << "method: " << method << std::endl;

    std::string pattern{"/server-info"};

    if(method == "GET") {
        // handler::handle_gets(pattern);
        h.handle(pattern);
    }
}
static int on_message_begin(http_parser *p) {
    std::cout << "########### on_message_begin ################" << std::endl;
    return 0;
}
static int on_url(http_parser* p, const char *at, size_t length) {
    std::string url(at);
    std::cout << "########## on_url: " << url.substr(0, length) << std::endl;

    return 0;
}
static int on_status(http_parser* p, const char *at, size_t length) {
    std::string status(at);
    std::cout << "########## on_status: " << status.substr(0, length) << std::endl;
    return 0;
}
static int on_header_field(http_parser* p, const char *at, size_t length) {
    std::string v(at);
    std::cout << "###### on_header_field: " << v.substr(0, length) << std::endl;
    return 0;
}
static int on_header_value(http_parser* p, const char *at, size_t length) {
    std::string v(at);
    std::cout << "###### on_header_value: " << v.substr(0, length) << std::endl;
    return 0;
}
static int on_body(http_parser* p, const char *at, size_t length) {
    std::string payload(at);
    std::string body = payload.substr(0, length);
    std::cout << "##### on_body: " << body << std::endl;

    // json j = json::parse(body);
    // auto p2 = j.get<ns::Body>();

    // std::cout << "image path: " << p2.image_path << std::endl;
    return 0;
}
}
}