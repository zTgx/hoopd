#ifndef __HOOPD_RESPONSE_H_
#define __HOOPD_RESPONSE_H_

#include <hoopd/internal/descriptable.h>
#include <hoopd/internal/nocopyable.h>

namespace hoopd {
class Response : public Descriptable, public noncopyable {
public:
    Response();
    virtual ~Response();

public: 
    const void description() const;

public:
    bool reset();
};
}

#endif