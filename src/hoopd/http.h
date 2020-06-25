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
 * HTTP supported METHODs
 * 
*/
enum class Method {
    GET = 0,
    POST,
    PUT,
    DELETE,
    UPDATE,
    UNKNOW_METHOD,
};

/**
 * 
 * HTTP supported VERSIONs
 * 
*/
enum class HttpVersion {
    v1_0 = 0, 
    v1_1,
    V2_0 
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
    void add_entity(const std::string& key, const std::string &val);
    void set_params(const Params& p);

    Headers get_headers() const;
    Params get_params() const;

public:
    std::string data() const;

private:
    Headers _headers;
    Params  _params;
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
    HttpVersion version;
    Method      method;
    std::string target;
    std::string path;
    HttpHeader  _http_header;
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

    void set_header(const std::string&, const std::string&);
    void set_body(std::string&);

    const HttpHeader get_header() const;
    const std::string get_body() const;

private:
    HttpHeader _http_header;
    std::string _body;

public:
    bool reset();
};
} // namespace http
} // namespace hoopd

#endif
