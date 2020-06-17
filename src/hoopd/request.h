#include <hoopd/internal/descriptable.h>
#include <hoopd/internal/httpheader.h>

namespace hoopd {
class Request : public Descriptable {
public:
    // Constructor
    Request();

    // Destructor
    virtual ~Request();
    
public:
    const void description() const;

public:
    Method method;
    
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