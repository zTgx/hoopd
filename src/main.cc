#include <iostream>
#include <httplib.h>
#include <seephit.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

using namespace httplib;
using namespace std;

void callback(ostream &, const string &sParam, spt::template_vals &) {

}

void init_spt() {
    constexpr auto parser =
    R"*(
    <span >
    <p  color="red" height='10' >{{name}} is a {{profession}} in {{city}}</p  >
    </span>
    )*"_html;

    spt::tree spt_tree(parser);

    spt::template_vals dct;
    dct["name"] = "Mary";
    dct["profession"] = "doctor";
    dct["city"] = "London";

    spt::template_funs calls;
    calls.insert (std::make_pair<std::string, spt::template_fun>("call", callback));

    spt_tree.root().render(cerr, dct, calls);
    cerr << endl;

    dct["city"] = "New York";
    dct["name"] = "John";
    dct["profession"] = "janitor";

    spt_tree.root().render(cerr, dct, calls);
    cerr << endl;
}

void run() {
    Server svr;

    svr.Get("/", [](const Request& req, Response& res) {
        res.set_content("Hello World!", "text/plain");
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
  spdlog::info("Welcome to spdlog!");

  init_spt();
  run();
}
