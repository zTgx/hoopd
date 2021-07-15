#ifndef _HOOPD_INTERNAL_PARSER_H_
#define _HOOPD_INTERNAL_PARSER_H_

#include <iostream>
#include <vector>
#include <unordered_map>
#include <internal/nocopyable.h>
#include <3rd/httpparser/http_parser.h>

#include <hoopd.h>

namespace hoopd {
namespace http {
class HttpParser : public noncopyable {
public:
    Message parse(const char*, long);

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