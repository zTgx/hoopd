namespace hoopd {
    class Request {
        public:
            // Constructor
            Request();

            // Destructor
            ~Request();
            
            // Copy Constructor
            Request(const Request&);

            // Copy Assignment Operator
            Request& operator=(const Request& rhs);

            // Move Constructor
            Request(Request&& moved);

            // Move Assignment Operator
            Request& operator=(Request&& moved);

        public:
            bool reset();
    };
}