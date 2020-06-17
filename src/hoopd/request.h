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
    Method method;
    Headers headers;
    
public:
    bool reset();
};
}

#endif