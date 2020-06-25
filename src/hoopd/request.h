#ifndef __HOOPD_REQUEST_H_
#define __HOOPD_REQUEST_H_

#include <hoopd/internal/descriptable.h>
#include <hoopd/internal/http_header.h>
#include <hoopd/internal/nocopyable.h>
#include <hoopd/internal/parser.h>

namespace hoopd {
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
    http::Params params;

public:
    bool reset();
};
}

#endif