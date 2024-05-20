#include "../include/restfullcpp/rest_client.hpp"
#include "../include/restfullcpp/exceptions.hpp"
#include <curl/curl.h>

namespace restfulcpp {

    RestClient::RestClient(const std::string& base_url) : base_url(base_url) {}

    void RestClient::addHeader(const std::string& key, const std::string& value) {
        headers[key] = value;
    }

    void RestClient::removeHeader(const std::string& key) {
        headers.erase(key);
    }

    void RestClient::setBasicAuth(const std::string& username, const std::string& password) {
        std::string auth = username + ":" + password;
        basic_auth = "Basic " + std::string(curl_easy_escape(nullptr, auth.c_str(), auth.size()));
        addHeader("Authorization", basic_auth);
    }

    void RestClient::setBearerToken(const std::string& token) {
        bearer_token = "Bearer " + token;
        addHeader("Authorization", bearer_token);
    }

    void RestClient::clearAuth() {
        removeHeader("Authorization");
        basic_auth.clear();
        bearer_token.clear();
    }

    Response RestClient::get(const std::string& endpoint) {
        return request("GET", endpoint);
    }

    Response RestClient::post(const std::string& endpoint, const nlohmann::json& data) {
        return request("POST", endpoint, &data);
    }

    Response RestClient::put(const std::string& endpoint, const nlohmann::json& data) {
        return request("PUT", endpoint, &data);
    }

    Response RestClient::del(const std::string& endpoint) {
        return request("DELETE", endpoint);
    }

    Response RestClient::request(const std::string& method, const std::string& endpoint, const nlohmann::json* data) {
        CURL* curl;
        CURLcode res;
        std::string readBuffer;
        long http_code = 0;

        curl = curl_easy_init();
        if (curl) {
            std::string url = base_url + endpoint;

            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method.c_str());

            struct curl_slist* headers_list = nullptr;
            for (const auto& header : headers) {
                headers_list = curl_slist_append(headers_list, (header.first + ": " + header.second).c_str());
            }
            curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers_list);

            if (data) {
                std::string json_data = data->dump();
                curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_data.c_str());
                curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, json_data.size());
            }

            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* contents, size_t size, size_t nmemb, void* userp) {
                ((std::string*)userp)->append((char*)contents, size * nmemb);
                return size * nmemb;
                });
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

            res = curl_easy_perform(curl);
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            curl_easy_cleanup(curl);

            if (headers_list) {
                curl_slist_free_all(headers_list);
            }

            if (res != CURLE_OK) {
                throw NetworkException("cURL error: " + std::string(curl_easy_strerror(res)));
            }

            if (http_code >= 400) {
                throw HttpRequestException(http_code, "HTTP error: " + std::to_string(http_code));
            }
        }
        else {
            throw NetworkException("Failed to initialize cURL");
        }

        try {
            return Response(http_code, readBuffer);
        }
        catch (const nlohmann::json::parse_error& e) {
            throw JsonParseException("Failed to parse JSON response: " + std::string(e.what()));
        }
    }

} // namespace restfulcpp
