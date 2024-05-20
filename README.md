# RestfulCpp

RestfulCpp is a modern C++ library designed for consuming RESTful APIs with ease. It uses the cURL library for HTTP requests and supports JSON response parsing with the nlohmann::json library. This library is designed to provide a simple, clean, and efficient way to interact with REST APIs in your C++ projects.

## Features

- **HTTP Methods**: Supports GET, POST, PUT, and DELETE.
- **Headers**: Easily add and remove custom headers.
- **Authentication**: Supports Basic Authentication and Bearer Token Authentication.
- **JSON Handling**: Automatically parses JSON responses.
- **Error Handling**: Comprehensive error handling for network issues, HTTP errors, and JSON parsing errors.

## Requirements

- C++17 or later
- [cURL](https://curl.se/libcurl/)
- [nlohmann::json](https://github.com/nlohmann/json)

## Installation

### Using CMake

1. Clone the repository:
    ```sh
    git clone https://github.com/yourusername/RestfulCpp.git
    ```

2. Create a build directory and navigate into it:
    ```sh
    mkdir build && cd build
    ```

3. Configure and build the project:
    ```sh
    cmake ..
    make
    ```

## Directory Structure

project_name/
│
├── include/
│ └── restfulcpp/
│ ├── rest_client.hpp
│ ├── response.hpp
│ └── exceptions.hpp
│
├── src/
│ └── rest_client.cpp
│ └── exceptions.cpp
│
├── tests/
│ └── main.cpp
│
└── CMakeLists.txt

## Usage

### Basic GET Request

```cpp 
#include <iostream>
#include "restfulcpp/rest_client.hpp"

int main() {
    try {
        restfulcpp::RestClient client("https://jsonplaceholder.typicode.com");
        restfulcpp::Response response = client.get("/posts/1");

        std::cout << "Status Code: " << response.getStatusCode() << std::endl;
        std::cout << "Body: " << response.getBody() << std::endl;
    } catch (const restfulcpp::HttpRequestException& ex) {
        std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
    } catch (const restfulcpp::JsonParseException& ex) {
        std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
    } catch (const restfulcpp::NetworkException& ex) {
        std::cerr << "Network Exception: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
```
### POST Request with JSON Data

```cpp
#include <iostream>
#include "restfulcpp/rest_client.hpp"

int main() {
    try {
        restfulcpp::RestClient client("https://jsonplaceholder.typicode.com");
        nlohmann::json postData = {
            {"title", "foo"},
            {"body", "bar"},
            {"userId", 1}
        };
        restfulcpp::Response response = client.post("/posts", postData);

        std::cout << "Status Code: " << response.getStatusCode() << std::endl;
        std::cout << "Body: " << response.getBody() << std::endl;
    } catch (const restfulcpp::HttpRequestException& ex) {
        std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
    } catch (const restfulcpp::JsonParseException& ex) {
        std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
    } catch (const restfulcpp::NetworkException& ex) {
        std::cerr << "Network Exception: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
```
### PUT Request with JSON Data
```cpp
#include <iostream>
#include "restfulcpp/rest_client.hpp"

int main() {
    try {
        restfulcpp::RestClient client("https://jsonplaceholder.typicode.com");
        nlohmann::json putData = {
            {"id", 1},
            {"title", "foo"},
            {"body", "bar"},
            {"userId", 1}
        };
        restfulcpp::Response response = client.put("/posts/1", putData);

        std::cout << "Status Code: " << response.getStatusCode() << std::endl;
        std::cout << "Body: " << response.getBody() << std::endl;
    } catch (const restfulcpp::HttpRequestException& ex) {
        std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
    } catch (const restfulcpp::JsonParseException& ex) {
        std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
    } catch (const restfulcpp::NetworkException& ex) {
        std::cerr << "Network Exception: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
```
### PUT Request with JSON Data

```cpp

#include <iostream>
#include "restfulcpp/rest_client.hpp"

int main() {
    try {
        restfulcpp::RestClient client("https://jsonplaceholder.typicode.com");
        nlohmann::json putData = {
            {"id", 1},
            {"title", "foo"},
            {"body", "bar"},
            {"userId", 1}
        };
        restfulcpp::Response response = client.put("/posts/1", putData);

        std::cout << "Status Code: " << response.getStatusCode() << std::endl;
        std::cout << "Body: " << response.getBody() << std::endl;
    } catch (const restfulcpp::HttpRequestException& ex) {
        std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
    } catch (const restfulcpp::JsonParseException& ex) {
        std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
    } catch (const restfulcpp::NetworkException& ex) {
        std::cerr << "Network Exception: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
```
### DELETE Request

```cpp

#include <iostream>
#include "restfulcpp/rest_client.hpp"

int main() {
    try {
        restfulcpp::RestClient client("https://jsonplaceholder.typicode.com");
        restfulcpp::Response response = client.del("/posts/1");

        std::cout << "Status Code: " << response.getStatusCode() << std::endl;
        std::cout << "Body: " << response.getBody() << std::endl;
    } catch (const restfulcpp::HttpRequestException& ex) {
        std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
    } catch (const restfulcpp::JsonParseException& ex) {
        std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
    } catch (const restfulcpp::NetworkException& ex) {
        std::cerr << "Network Exception: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
```
### Authentication
#### Basic Authentication

```cpp

#include <iostream>
#include "restfulcpp/rest_client.hpp"

int main() {
    try {
        restfulcpp::RestClient client("https://api.example.com");
        client.setBasicAuth("username", "password");
        restfulcpp::Response response = client.get("/protected/resource");

        std::cout << "Status Code: " << response.getStatusCode() << std::endl;
        std::cout << "Body: " << response.getBody() << std::endl;
    } catch (const restfulcpp::HttpRequestException& ex) {
        std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
    } catch (const restfulcpp::JsonParseException& ex) {
        std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
    } catch (const restfulcpp::NetworkException& ex) {
        std::cerr << "Network Exception: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
```
### Bearer Token Authentication

```cpp

#include <iostream>
#include "restfulcpp/rest_client.hpp"

int main() {
    try {
        restfulcpp::RestClient client("https://api.example.com");
        client.setBearerToken("your_bearer_token");
        restfulcpp::Response response = client.get("/protected/resource");

        std::cout << "Status Code: " << response.getStatusCode() << std::endl;
        std::cout << "Body: " << response.getBody() << std::endl;
    } catch (const restfulcpp::HttpRequestException& ex) {
        std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
    } catch (const restfulcpp::JsonParseException& ex) {
        std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
    } catch (const restfulcpp::NetworkException& ex) {
        std::cerr << "Network Exception: " << ex.what() << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }

    return 0;
}
```

## Error Handling

RestfulCpp provides comprehensive error handling for network issues, HTTP errors, and JSON parsing errors. The following exceptions are available:

    NetworkException: Thrown when there is a network-related issue.
    HttpRequestException: Thrown when an HTTP request returns a status code >= 400.
    JsonParseException: Thrown when there is an error parsing the JSON response.

Example:
```cpp
try {
    // Your code...
} catch (const restfulcpp::HttpRequestException& ex) {
    std::cerr << "HTTP Request Exception: " << ex.what() << " (Status Code: " << ex.getStatusCode() << ")" << std::endl;
} catch (const restfulcpp::JsonParseException& ex) {
    std::cerr << "JSON Parse Exception: " << ex.what() << std::endl;
} catch (const restfulcpp::NetworkException& ex) {
    std::cerr << "Network Exception: " << ex.what() << std::endl;
} catch (const std::exception& ex) {
    std::cerr << "Exception: " << ex.what() << std::endl;
}
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.
