cmake_minimum_required(VERSION 3.10)
project(RestfulCpp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(restfulcpp
    src/rest_client.cpp
    src/exceptions.cpp
)

target_include_directories(restfulcpp
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(tests
    tests/main.cpp
)

target_link_libraries(tests
    PRIVATE restfulcpp
)
