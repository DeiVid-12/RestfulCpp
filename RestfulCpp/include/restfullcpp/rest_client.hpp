#ifndef RESTFULCPP_REST_CLIENT_HPP
#define RESTFULCPP_REST_CLIENT_HPP

#include <string>
#include <unordered_map>
#include <nlohmann/json.hpp>
#include "response.hpp"
#include "exceptions.hpp"

namespace restfulcpp {

    class RestClient {
    public:
        RestClient(const std::string& base_url);

        void addHeader(const std::string& key, const std::string& value);
        void removeHeader(const std::string& key);

        void setBasicAuth(const std::string& username, const std::string& password);
        void setBearerToken(const std::string& token);
        void clearAuth();

        Response get(const std::string& endpoint);
        Response post(const std::string& endpoint, const nlohmann::json& data);
        Response put(const std::string& endpoint, const nlohmann::json& data);
        Response del(const std::string& endpoint);

    private:
        std::string base_url;
        std::unordered_map<std::string, std::string> headers;
        std::string basic_auth;
        std::string bearer_token;

        Response request(const std::string& method, const std::string& endpoint, const nlohmann::json* data = nullptr);
    };

} // namespace restfulcpp

#endif // RESTFULCPP_REST_CLIENT_HPP
