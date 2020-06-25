#ifndef _HOOPD_INTERNAL_PARSER_H_
#define _HOOPD_INTERNAL_PARSER_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <hoopd/internal/nocopyable.h>
#include <hoopd/3rd/httpparser/http_parser.h>

namespace hoopd {
namespace http {
    typedef std::unordered_map<std::string, std::string> Params;

struct Message {
    std::vector<std::string> fields;
    std::vector<std::string> values;
    std::string path;
    std::string body;
    std::string method;
    std::string version;
    std::string query;
    Params params;
};

class HttpParser : public noncopyable {
public:
    Message parse(const char*, long);

private:
    Params parse_params() const;

private:
    Message message;
};

static int on_message_begin(http_parser *p);
static int on_url(http_parser* p, const char *at, size_t length);
static int on_status(http_parser* p, const char *at, size_t length);
static int on_header_field(http_parser* p, const char *at, size_t length);
static int on_header_value(http_parser* p, const char *at, size_t length);
static int on_headers_complete(http_parser *p);
static int on_body(http_parser* p, const char *at, size_t length);
static int on_message_complete(http_parser *p);
}
}

#endif