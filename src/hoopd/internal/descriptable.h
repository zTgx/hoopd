#ifndef __HOOPD_DESCRIPTABLE_H_
#define __HOOPD_DESCRIPTABLE_H_

namespace hoopd {
class Descriptable {
public:
    virtual const void description() const = 0;
};
}

#endif