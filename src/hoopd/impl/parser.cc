#include <hoopd/internal/parser.h>
#include <hoopd/internal/http_header.h>

namespace hoopd {
namespace http {
Message HttpParser::parse(const char* buffer, long data_len) {
    http_parser_settings settings = {
        .on_message_begin       = on_message_begin,
        .on_url                 = on_url,
        .on_status              = on_status,
        .on_header_field        = on_header_field,
        .on_header_value        = on_header_value,
        .on_headers_complete    = on_headers_complete,
        .on_body                = on_body,
        .on_message_complete    = on_message_complete,        
    };

    struct http_parser parser;

    http_parser_init(&parser, HTTP_REQUEST);

    parser.data = (void*)&message;

    http_parser_execute(&parser, &settings, buffer, data_len);
    
    return message;
}
static int on_message_begin(http_parser *p) {
    return 0;
}
static int on_url(http_parser* p, const char *at, size_t length) {
    std::string url(at);
    std::string pattern = url.substr(0, length);

    Message *message = (struct Message*)p->data;
    message->url = pattern;

    return 0;
}
static int on_status(http_parser* p, const char *at, size_t length) {
    return 0;
}
static int on_header_field(http_parser* p, const char *at, size_t length) {
    std::string v(at);
    std::string field{v.substr(0, length)};
 
    Message *message = (struct Message*)p->data;
    message->fields.push_back(field);

    return 0;
}
static int on_header_value(http_parser* p, const char *at, size_t length) {
    std::string v(at);
    std::string value{v.substr(0, length)};

    Message *message = (struct Message*)p->data;
    message->values.push_back(value);

    return 0;
}
static int on_headers_complete(http_parser *p) {
    std::string method{http_method_str((enum http_method)p->method)};
    std::string version{std::to_string(p->http_major) + std::to_string(p->http_minor)};

    Message *message = (struct Message*)p->data;
    message->version = version;
    message->method = method;

    return 0;
}
static int on_body(http_parser* p, const char *at, size_t length) {
    std::string payload(at);
    std::string body = payload.substr(0, length);
    
    Message *message = (struct Message*)p->data;
    message->body = body;

    return 0;
}
static int on_message_complete(http_parser *p) {
    return 0;
}
}
}