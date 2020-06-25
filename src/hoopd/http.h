#ifndef __HOOPD_INTERNAL_HTTPHEADER_H_
#define __HOOPD_INTERNAL_HTTPHEADER_H_

#include <iostream>
#include <unordered_map>
#include <hoopd/3rd/json/json.hpp>

namespace hoopd {
namespace http {
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
    GET,
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
 
} // namespace http
} // namespace hoopd

#endif
