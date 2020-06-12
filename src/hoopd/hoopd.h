
namespace hoopd {
    class HttpServer {
        public:
            // Constructor
            HttpServer();

            // Destructor
            ~HttpServer();
            
            // Copy Constructor
            HttpServer(const HttpServer&);

            // Copy Assignment Operator
            HttpServer& operator=(const HttpServer& rhs);

            // Move Constructor
            HttpServer(HttpServer&& moved);

            // Move Assignment Operator
            HttpServer& operator=(HttpServer&& moved);

        public:
            // HttpServer run 
            virtual bool run() = 0;
    };
}