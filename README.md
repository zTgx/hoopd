# [hoopd](https://github.com/zTgx/hoopd) ![C/C++ CI](https://github.com/zTgx/hoopd/workflows/C/C++%20CI/badge.svg)
hoopd will be a simple and easy to use restful server written in C++11.   

## Basic Usage
* Server
```c++
#include <hoopd/hoopd.h>

using namespace hoopd;

class Echo {
public:
    std::string echo() {
        std::string body{"Hi there; my name is hoopd, Good to see you."};
        return body;
    }
};

int main() {
    HttpServer server;
    server.set_scope("/api/v2");

    server.get("/echo", [](const http::Request& req, http::Response& res) {
        Echo e;
        std::string message = e.echo();

        std::string k{"Cache-control"};
        std::string v{"no-cache"};
        res.header.headers(k, v);
        
        res.body = message;

        req.description();
        res.description();
    });

    server.run();
}
```
* client: Use curl
```c
curl http://127.0.0.1:9527/api/v2/echo
```
* client: Or Use python
```c
python client.py
```
* output 
```
Hi there; my name is hoopd, Good to see you.
```
  
Examples
---------------
More examples can be found [in the examples directory](examples/).  


NOTE
----

### Build Tools
g++ 8.4  +   
cmake 3.17 +


License
-------

MIT license (© 2020 zTgx)
