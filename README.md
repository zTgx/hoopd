# [hoopd](https://github.com/zTgx/hoopd)
hoopd will be a simple and easy to use restful server written in C++11.   

---
## How To Use
```c++
#include <hoopd/hoopd.h>

using namespace hoopd;

int main() {
    HttpServer server;
    server.set_scope("/api/v2");

    class Echo {
    public:
        void echo() {
            std::cout << "fixed echo." << std::endl;
        }
    };
    server.get("/echo", [](const Request& req, Response& res) {
        Echo e;
        e.echo();
    });

    server.run();
}
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
