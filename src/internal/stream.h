#ifndef __HOOPD_INTERNAL_STREAM_H_
#define __HOOPD_INTERNAL_STREAM_H_

#include <internal/nocopyable.h>
#include <string>
#include <sstream>

namespace hoopd {
class Stream : public noncopyable {
public:
    explicit Stream(int);

public:
    void send();
    const std::string data() const;

public:
    std::stringstream& get();
    
private:
    int _sock;
    std::stringstream _ss;
};
Stream& operator<<(Stream&, const std::string&);
Stream& operator<<(Stream&, const char*);
}

#endif