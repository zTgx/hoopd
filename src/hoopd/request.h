namespace hoopd {
class Request {
public:
    // Constructor
    Request();

    // Destructor
    virtual ~Request();
    
public:
    // Copy Constructor
    Request(const Request&) = delete;

    // Copy Assignment Operator
    Request& operator=(const Request& rhs) = delete;

    // Move Constructor
    Request(Request&& moved) = delete;

    // Move Assignment Operator
    Request& operator=(Request&& moved) = delete;

public:
    bool reset();
};
}