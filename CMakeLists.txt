cmake_minimum_required(VERSION 3.10)
project(HelloWorldCMake)

find_package(XercesC REQUIRED)

add_executable(hello_world_cmake src/hello.cpp)

target_link_libraries(hello_world_cmake PRIVATE XercesC::XercesC)
