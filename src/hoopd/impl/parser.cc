#include <hoopd/internal/parser.h>

namespace hoopd {
namespace http {
static Message message;

void Message::on_message_begin() {
    std::cout << "on_message_begin..." << std::endl;

    fields.clear();
    values.clear();

    url.clear();

    body.clear();
}
void Message::description() {
    json field_and_value;
    for(auto i=0;i<fields.size();i++) {
        std::cout << fields[i] << ":" << values[i] << std::endl;
        field_and_value.emplace(fields[i], values[i]);
    }
    std::cout << std::endl;

    field_and_value.emplace("method", method);
    std::cout << "method: " << method << std::endl;

    field_and_value.emplace("url", url);
    std::cout << "url: " << url << std::endl;

    field_and_value.emplace("body", body);
    std::cout << "json: " << body.dump() << std::endl;

    data = field_and_value;
}
json HttpParser::parse(const char* buffer, long data_len, Handler& h) {
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

    size_t parsed;
    http_parser_init(&parser, HTTP_REQUEST);

    parsed = http_parser_execute(&parser, &settings, buffer, data_len);
    std::cout << "parsed: " << parsed << std::endl;

    std::string pattern{"/server-info"};

    if(true) {
        h.handle(pattern);
    }

    return message.data;
}
static int on_message_begin(http_parser *p) {
    std::cout << "########### on_message_begin ################" << std::endl;
    message.on_message_begin();
    return 0;
}
static int on_url(http_parser* p, const char *at, size_t length) {
    std::string url(at);
    std::string pattern = url.substr(0, length);
    std::cout << "########## on_url: " << pattern << std::endl;

    message.url = pattern;

    return 0;
}
static int on_status(http_parser* p, const char *at, size_t length) {
    std::string status(at);
    std::cout << "########## on_status: " << status.substr(0, length) << std::endl;
    return 0;
}
static int on_header_field(http_parser* p, const char *at, size_t length) {
    std::string v(at);
    std::string field{v.substr(0, length)};
    std::cout << "###### on_header_field: " << field << std::endl;

    message.fields.push_back(field);

    return 0;
}
static int on_header_value(http_parser* p, const char *at, size_t length) {
    std::string v(at);
    std::string value{v.substr(0, length)};
    std::cout << "###### on_header_value: " << value << std::endl;

    message.values.push_back(value);

    return 0;
}
static int on_headers_complete(http_parser *p) {
    std::string method{http_method_str((enum http_method)p->method)};

    message.method = method;

    return 0;
}
static int on_body(http_parser* p, const char *at, size_t length) {
    std::string payload(at);
    std::string body = payload.substr(0, length);
    std::cout << "##### on_body: " << body << std::endl;

    json j = json::parse(body);
    std::cout << "image path : " << j["image_path"] << std::endl;

    message.body = j;

    // auto p2 = j.get<ns::Body>();
    // std::cout << "image path: " << p2.image_path << std::endl;
    return 0;
}
static int on_message_complete(http_parser *p) {
    message.description();
    return 0;
}
}
}