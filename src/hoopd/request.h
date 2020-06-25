#ifndef __HOOPD_REQUEST_H_
#define __HOOPD_REQUEST_H_

#include <hoopd/internal/descriptable.h>
#include <hoopd/internal/nocopyable.h>
#include <hoopd/internal/parser.h>

#include <hoopd/http.h>

namespace hoopd {
using namespace http;

class Request : public Descriptable, 
                public noncopyable {
public:
    explicit Request();
    explicit Request(const http::Message&);
    virtual ~Request();
    
public:
    const void description() const;

public:
    HttpVersion version;
    Method      method;
    std::string target;
    std::string path;
    HttpHeader  _http_header;
    std::string body;

public:
    bool reset();
};
}

#endif