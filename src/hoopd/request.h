#ifndef __HOOPD_REQUEST_H_
#define __HOOPD_REQUEST_H_

#include <hoopd/internal/descriptable.h>
#include <hoopd/internal/httpheader.h>
#include <hoopd/internal/nocopyable.h>

namespace hoopd {
class Request : public Descriptable, public noncopyable {
public:
    Request();
    virtual ~Request();
    
public:
    const void description() const;

public:
    std::string version;
    Method      method;
    std::string target;
    std::string path;
    Headers     headers;
    std::string body;
    
public:
    void set_header(const char *key, const char *val);
    void set_header(const char *key, const std::string &val);
    std::string get_header_value(const char *key) const;

public:
    bool reset();
};
}

#endif