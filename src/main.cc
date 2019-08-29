#include <iostream>
#include <sstream>
#include <httplib.h>
#include <seephit.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <leveldb/db.h>

using namespace httplib;
using namespace std;
using namespace leveldb;

void leveldb_init() {
    DB *db;
    Options options;
    options.create_if_missing = true;

    Status s = DB::Open(options,"./data/login.db",&db);
    if(!s.ok()){
          cerr << s.ToString() << endl;exit(-1);
    }
    string key = "name",val = "ciaos";
    s = db->Put(WriteOptions(),key,val);
    if(!s.ok()){
          cerr << s.ToString() << endl;exit(-1);
    }
    s = db->Get(ReadOptions(),key,&val);
    if(s.ok()){
          cout << key << "=" << val << endl;
          s = db->Put(leveldb::WriteOptions(),"key2",val);
          if(s.ok()){
                  s = db->Delete(leveldb::WriteOptions(),key);
                  if(!s.ok()){
                          cerr << s.ToString() << endl;exit(-1);
                  }
          }
    }
}

void callback(ostream &, const string &sParam, spt::template_vals &) {

}

std::string init_spt() {
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

    std::stringstream buffer;

    spt_tree.root().render(buffer, dct, calls);
    buffer << endl;

    dct["city"] = "New York";
    dct["name"] = "John";
    dct["profession"] = "janitor";

    spt_tree.root().render(buffer, dct, calls);
    buffer << endl;

    std::string s;
    buffer >> s;

    spdlog::info(s);

    return s;
}

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
  spdlog::info("Welcome to spdlog!");
  spdlog::error("Some error message with arg: {}", 1);
  spdlog::warn("Easy padding in numbers like {:08d}", 12);
  spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
  spdlog::debug("This message should be displayed..");

  leveldb_init();

  // std::string s = init_spt();
  // run(s);

}
