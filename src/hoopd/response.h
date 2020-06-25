#ifndef __HOOPD_RESPONSE_H_
#define __HOOPD_RESPONSE_H_

#include <hoopd/internal/descriptable.h>
#include <hoopd/internal/nocopyable.h>

#include <hoopd/http.h>

namespace hoopd {
using namespace http;

class Response : public Descriptable, public noncopyable {
public:
    Response();
    virtual ~Response();

public: 
    const void description() const;

    void set_header(const std::string&, const std::string&);
    void set_body(std::string&);

    const HttpHeader get_header() const;
    const std::string get_body() const;

private:
    HttpHeader _http_header;
    std::string _body;

public:
    bool reset();
};
}

#endif