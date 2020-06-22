# [hoopd](https://github.com/zTgx/hoopd)
hoopd will be a simple and easy to use restful server written in C++11.   

---
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

    server.get("/echo", [](const Request& req, Response& res) {
        Echo e;
        std::string message = e.echo();
        res.set_body(message);
    });

    server.run();
}
```
* client
```c
curl http://127.0.0.1:9527/api/v2/echo
```
* output 
```
Hi there; my name is hoopd, Good to see you.
```
---  
## How to run helloworld
#### Zero : clone source code
```shell
git clone https://github.com/zTgx/hoopd.git
```
#### One: build hoopd library
```shell
mkdir build && cd build && cmake .. && make
```
#### Two: build helloworld
```shell
cd examples/helloworld && mkdir build && cd build && cmake .. && make 
```
#### Last: run helloworld binary
```shell
./bin/helloworld
```
