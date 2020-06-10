#include <iostream>
#include <sstream>
#include <httplib.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace httplib;
using namespace std;

void run(std::string& s) {
    Server svr;

    svr.Get("/", [s](const Request& req, Response& res) {
        //res.set_content("Hello World!", "text/plain");
        res.set_content(s.c_str(), "text/plain");
    });

    svr.Get("/hi", [](const Request& req, Response& res) {
        res.set_content("Hello World!", "text/plain");

    });

    svr.Get(R"(/numbers/(\d+))", [&](const Request& req, Response& res) {
        auto numbers = req.matches[1];
        res.set_content(numbers, "text/plain");
    });

    svr.Get("/stop", [&](const Request& req, Response& res) {
        svr.stop();
    });

    std::cout << "\nlistening at localhost:1234" << std::endl;
    svr.listen("localhost", 1234);
}

int main() {
    std::string welcome("Welcome to hoopd!");
    spdlog::info(welcome);

    run(welcome);
}
