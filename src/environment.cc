#include <environment.h>
#include <string>
#include <fstream>
#include <sys/prctl.h>

namespace hoopd {
bool
Environment::haveChecking() {
    return true;
}

void 
Environment::setCallingThreadName (const char* n)
{
    static std::string pName;

    if (pName.empty ())
    {
        std::ifstream cLine ("/proc/self/cmdline", std::ios::in);
        cLine >> pName;

        if (pName.empty ())
            pName = "skywelld";
        else
        {
            size_t zero = pName.find_first_of ('\0');

            if ((zero != std::string::npos) && (zero != 0))
                pName = pName.substr (0, zero);

            size_t slash = pName.find_last_of ('/');

            if (slash != std::string::npos)
                pName = pName.substr (slash + 1);
        }

        pName += " ";
    }

    prctl (PR_SET_NAME, (pName + n).c_str (), 0, 0, 0);
}

}