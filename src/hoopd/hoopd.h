
namespace hoopd {
class HttpServer {
public:
    // Constructor
    HttpServer();

    // Destructor
    virtual ~HttpServer();
    
public:
    // HttpServer run 
    virtual bool run();

public:
    // Copy Constructor
    HttpServer(const HttpServer&) = delete;

    // Copy Assignment Operator
    HttpServer& operator=(const HttpServer& rhs) = delete;

    // Move Constructor
    HttpServer(HttpServer&& moved) = delete;

    // Move Assignment Operator
    HttpServer& operator=(HttpServer&& moved) = delete;
};
}