#ifndef RESTFULCPP_RESPONSE_HPP
#define RESTFULCPP_RESPONSE_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace restfulcpp {

    class Response {
    public:
        Response(long status_code, const std::string& body);

        long getStatusCode() const;
        const std::string& getBody() const;
        const nlohmann::json& getJson() const;

    private:
        long status_code;
        std::string body;
        nlohmann::json json_body;
    };

} // namespace restfulcpp

#endif // RESTFULCPP_RESPONSE_HPP
