// "Sustain" is a system for a buddy process that monitors the main process
// and relaunches it on a fault.

#pragma once

#include <string>

namespace hoopd {
    class Sustain {
        public:
            bool haveSustain () const;
            std::string stopSustain ();
            std::string doSustain (std::string const& logFile);
    };
}