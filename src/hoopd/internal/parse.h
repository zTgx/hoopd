#include <iostream>
#include <hoopd/internal/http_parser.h>
#include <cassert>

namespace hoopd {
    
    static int on_message_begin(http_parser *p) {
        std::cout << "########### on_message_begin ################" << std::endl;
        return 0;
    }
    static int on_info(http_parser* p) {
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

    static int on_body(http_parser* p, const char *at, size_t length) {
        std::string body(at);
        std::cout << "##### on_body: " << body.substr(0, length) << std::endl;
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

    // designator order for field ‘http_parser_settings::on_header_field’ does not match declaration order in ‘http_parser_settings’
    static http_parser_settings settings = {
        .on_message_begin       = on_message_begin,
        .on_url                 = on_url,
        .on_status              = on_status,
        .on_header_field        = on_header_field,
        .on_header_value        = on_header_value,
        // .on_headers_complete    = on_info,
        .on_body                = on_body,
        // .on_message_complete    = on_info,        
    };

    void parse_http_header(const char* buffer, long data_len) {
        struct http_parser parser;

        size_t parsed;
        http_parser_init(&parser, HTTP_REQUEST);

        parsed = http_parser_execute(&parser, &settings, buffer, data_len);
        std::cout << "parsed: " << parsed << std::endl;

        std::cout << "method: " << http_method_str((enum http_method)parser.method) << std::endl;
    }



}