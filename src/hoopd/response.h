namespace hoopd {
class Response {
public:
    // Constructor
    Response();

    // Destructor
    virtual ~Response();
    
public:
    // Copy Constructor
    Response(const Response&) = delete;

    // Copy Assignment Operator
    Response& operator=(const Response& rhs) = delete;

    // Move Constructor
    Response(Response&& moved) = delete;

    // Move Assignment Operator
    Response& operator=(Response&& moved) = delete;

public:
    bool reset();
};
}