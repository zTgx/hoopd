#ifndef __HOOPD_HTTP_H__
#define __HOOPD_HTTP_H__

#include <iostream>
#include <unordered_map>
#include <vector>

#include <hoopd/internal/descriptable.h>
#include <hoopd/internal/nocopyable.h>

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

public:
    std::string data() const;

private:
    Headers _headers;
    Params  _params;
    std::string _version;
    std::string _method;
    std::string _path;
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
} // namespace hoopd

#endif
