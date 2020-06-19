#ifndef __HOOPD_INTERNAL_HANDLER_H_
#define __HOOPD_INTERNAL_HANDLER_H_

#include <iostream>

namespace hoopd {
    namespace handler {
        void handle_gets(std::string& pattern) {
            std::cout << "pattern : " << pattern << std::endl;

            
        }
    }
}

#endif