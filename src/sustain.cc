#include <sustain.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <sys/wait.h>
#include <unistd.h>
#include <environment.h>

namespace hoopd {

static pid_t pManager = static_cast<pid_t> (0);
static pid_t pChild = static_cast<pid_t> (0);
static auto const sleepBeforeWaiting = 10;
static auto const sleepBetweenWaits = 1;

static void stop_manager (int)
{
    kill (pChild, SIGINT);
    _exit (0);
}

static void pass_signal (int a)
{
    kill (pChild, a);
}

bool 
Sustain::haveSustain() const {
    return true;
}

std::string 
Sustain::stopSustain () {
    if (getppid () != pManager)
        return "";

    kill (pManager, SIGHUP);

    return "Terminating monitor";
}

std::string 
Sustain::doSustain (std::string const& logFile) {
    pManager = getpid ();
    signal (SIGINT, stop_manager);
    signal (SIGHUP, stop_manager);
    signal (SIGUSR1, pass_signal);
    signal (SIGUSR2, pass_signal);

    for (auto childCount = 1;; ++childCount)
    {
        pChild = fork ();

        if (pChild == -1)
            _exit (0);

        auto cc = std::to_string (childCount);
        if (pChild == 0)
        {
            Environment::setCallingThreadName ("main");
            signal (SIGINT, SIG_DFL);
            signal (SIGHUP, SIG_DFL);
            signal (SIGUSR1, SIG_DFL);
            signal (SIGUSR2, SIG_DFL);
            return "Launching child " + cc;
        }

        Environment::setCallingThreadName (("#" + cc).c_str());

        sleep (sleepBeforeWaiting);

        for (;;)
        {
            int i;
            waitpid (pChild, &i, 0);
            if (kill (pChild, 0))
                break;
            sleep (sleepBetweenWaits);
        }

        auto pc = std::to_string (pChild);
        rename ("core", ("core." + pc).c_str ());
        if (!logFile.empty()) // FIXME: logFile hasn't been set yet
            rename (logFile.c_str(), (logFile + "." + pc).c_str ());
    }
}

} // end namespace
