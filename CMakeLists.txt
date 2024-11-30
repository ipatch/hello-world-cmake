cmake_minimum_required(VERSION 3.10)
project(HelloWorldCMake)

find_package(XercesC REQUIRED)

if(HOMEBREW_PREFIX)
  # NOTE: ipatch, possible bug / feature fix related to cmake
  # https://issues.apache.org/jira/browse/XERCESC-2246?jql=project%20%3D%20XERCESC
  # set xcercesc include directory manually
  set(XercesC_INCLUDE_DIR ${HOMEBREW_PREFIX}/opt/xerces-c/include)
  include_directories(${XercesC_INCLUDE_DIR})

  # Display information about Xerces-C++ found by CMake
  message(STATUS "ipatch -------------------------------------------------")
  message(STATUS "Xerces-C++ include directory: ${XercesC_INCLUDE_DIR}")
  message(STATUS "Xerces-C++ library: ${XercesC_LIBRARY}")
  message(STATUS "ipatch -------------------------------------------------")
endif()

if(NOT XercesC_FOUND)
  message(FATAL_ERROR "==================\n"
    "XercesC not found.\n"
    "==================\n")
endif(NOT XercesC_FOUND)

add_executable(hello_world_cmake src/hello.cpp)

target_link_libraries(hello_world_cmake PRIVATE XercesC::XercesC)

install(TARGETS hello_world_cmake
  RUNTIME DESTINATION bin)
