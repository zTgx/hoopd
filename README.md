# [hoopServer](https://github.com/zTgx/hoopServer)
A simple HTTP server.

### Usage
##### Step1
```shell
git clone --recursive https://github.com/zTgx/hoopServer.git
```
##### Step2
```shell
mkdir build && cd build
```
##### Step3
```shell
cmake .. && make
```
##### Step4
```shell
./bin/hoopServer
```

---
### depend
* [cpp-httplib](https://github.com/yhirose/cpp-httplib.git), a head-only http server.
* [spdlog](https://github.com/gabime/spdlog.git), a fast C++ logging library.
* [googletest](https://github.com/google/googletest.git), a Testing and mocking framework.