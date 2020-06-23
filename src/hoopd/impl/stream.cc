#include <hoopd/internal/stream.h>
#include <iostream>
#include <sys/socket.h> //send

namespace hoopd {
Stream::Stream(int sock) {
    _sock = sock;
}
void Stream::send() {
    ::send(_sock, _ss.str().data(), data().size(), 0);
}
const std::string Stream::data() const {
    return _ss.str();
}
std::stringstream& Stream::get() {
    return _ss;
}

Stream& operator<<(Stream& s, const std::string& ss) {
    s.get() << ss;

    return s;
}
Stream& operator<<(Stream& s, const char* ss) {
    s.get() << ss;

    return s;
}
}