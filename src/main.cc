#include <iostream>
#include <httplib.h>

using namespace httplib;

int main() {
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

  svr.listen("localhost", 1234);
}
