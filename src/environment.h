#pragma once

// 运行环境检查
namespace hoopd {
    class Environment {
        public:
            bool haveChecking();

        public:
            static void setCallingThreadName(const char*);
    };

} // end hoopd