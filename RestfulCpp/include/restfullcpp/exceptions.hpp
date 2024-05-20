#ifndef RESTFULCPP_EXCEPTIONS_HPP
#define RESTFULCPP_EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

namespace restfulcpp {

    class NetworkException : public std::runtime_error {
    public:
        NetworkException(const std::string& message);
    };

    class HttpRequestException : public std::runtime_error {
    public:
        HttpRequestException(long status_code, const std::string& message);
        long getStatusCode() const;

    private:
        long status_code;
    };

    class JsonParseException : public std::runtime_error {
    public:
        JsonParseException(const std::string& message);
    };

} // namespace restfulcpp

#endif // RESTFULCPP_EXCEPTIONS_HPP
