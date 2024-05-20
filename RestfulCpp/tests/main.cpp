#include <iostream>
#include "../include/restfullcpp/rest_client.hpp"

int main() {
    // Basic GET Request Example
    try {
        restfulcpp::RestClient client("https://jsonplaceholder.typicode.com");
        restfulcpp::Response response = client.get("/posts/1");

        std::cout << "Status Code: " << response.getStatusCode() << std::endl;
        std::cout << "Body: " << response.getBody() << std::endl;
    }
    catch (const restfulcpp::HttpRequestException& ex) {
        std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
    }
    catch (const restfulcpp::JsonParseException& ex) {
        std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
    }
    catch (const restfulcpp::NetworkException& ex) {
        std::cerr << "Network Exception: " << ex.what() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
