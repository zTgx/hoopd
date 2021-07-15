#ifndef __HOOPD_H__
#define __HOOPD_H__

#include <vector>
#include <regex>        // std::regex
#include <utility>      // std::pair
#include <functional>   // std::function
#include <unordered_map>

#include <internal/descriptable.h>
#include <internal/nocopyable.h>

namespace hoopd {
namespace http {
/**
 * 
 * Inner Message for Parser 
 * 
 * */    
struct Message {
// public:
    std::vector<std::string> fields;
    std::vector<std::string> values;
    std::string path;
    std::string body;
    std::string method;
    std::string version;
    std::string query;
    std::unordered_map<std::string, std::string> params;
};

/**
 * 
 * HTTP SETTINGS
 * 
*/
struct Settings {
    // Default HOST
    std::string host = "127.0.0.1"; 

    // Default PORT
    size_t      port = 9527;
};

/**
 * 
 * HTTP HEADERs
 * 
*/
class HttpHeader {
public:
    typedef std::unordered_map<std::string, std::string> Headers;
    typedef std::unordered_map<std::string, std::string> Params;

public:
    Headers headers() const;
    void headers(const std::string& key, const std::string &val);

    Params params() const;
    void params(const Params&);

    std::string version() const;
    void version(const std::string&);

    std::string method() const;
    void method(const std::string&);

    std::string path() const;
    void path(const std::string&);

    std::string query() const;
    void query(const std::string&);

public:
    std::string data() const;
    void dump() const;

private:
    Headers _headers;
    Params  _params;
    std::string _version;
    std::string _method;
    std::string _path;
    std::string _query;
};

/**
 * 
 * Request
 * 
*/
class Request : public Descriptable, 
                public noncopyable {
public:
    explicit Request();
    explicit Request(const Message&);
    virtual ~Request();
    
public:
    const void description() const;

public:
    HttpHeader  header;
    std::string body;

public:
    bool reset();
};

/**
 * 
 * Response
 * 
*/
class Response : public Descriptable, public noncopyable {
public:
    Response();
    virtual ~Response();

public: 
    const void description() const;

public:
    HttpHeader header;
    std::string body;

public:
    bool reset();
};
} // namespace http

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Handler {    
public:
    typedef std::function<void(const http::Request&, http::Response&)> Action;
    typedef std::vector<std::pair<std::regex, Action>> Routers;

public:
    Action handle(const std::string&);
    void push_back(const std::string&, Action);
    void push_error(Action h);

private:
    Routers _gets;
    Action _on_error;
};

class Service {
public:
    void set_handler(Handler&);
    void set_settings(const http::Settings&);
    bool run();

private:
    void handle_request(int);
    void set_nonblocking(int, bool);

private:
    http::Settings _settings;
    Handler _handler;
};

/**
 * 
 * HttpServer
 * 
*/
class HttpServer : public noncopyable {
public:
    explicit HttpServer();
    explicit HttpServer(const http::Settings&);
    virtual ~HttpServer();

public:
    bool is_running() const;

    virtual bool run();
    virtual bool stop();
    
public:
    HttpServer& set_scope(const std::string&);
    HttpServer& get(const std::string&, Handler::Action);
    HttpServer& post(const std::string&, Handler::Action);

    HttpServer& on_error(Handler::Action);

private:
    std::string _scope;

private:
    http::Settings _settings;
    Service _service;
    Handler _handler;
};
}

#endif