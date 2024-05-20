#include "../include/restfullcpp/exceptions.hpp"

namespace restfulcpp {

    NetworkException::NetworkException(const std::string& message) : std::runtime_error(message) {}

    HttpRequestException::HttpRequestException(long status_code, const std::string& message)
        : std::runtime_error(message), status_code(status_code) {}

    long HttpRequestException::getStatusCode() const {
        return status_code;
    }

    JsonParseException::JsonParseException(const std::string& message) : std::runtime_error(message) {}

} // namespace restfulcpp
