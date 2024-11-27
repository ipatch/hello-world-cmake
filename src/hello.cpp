// a simple hello world program written in c++

#include <iostream>
// #include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XercesVersion.hpp> // For Xerces-C++ version macros
#include <xercesc/util/XMLString.hpp> // Required for XMLString class
                                      //
int main() {
  std::cout << "hello world cpp" << std::endl;

  try {
    // Initialize Xerces
    xercesc::XMLPlatformUtils::Initialize();

    // Example usage of XMLString for string transcoding
    const char* sample = "Hello, Xerces!";
    XMLCh* wideChar = xercesc::XMLString::transcode(sample);
    std::cout << "Wide-char string: " << xercesc::XMLString::transcode(wideChar) << std::endl;

    // Clean up
    xercesc::XMLString::release(&wideChar);
    xercesc::XMLPlatformUtils::Terminate();
  } catch (const xercesc::XMLException& e) {
    char* message = xercesc::XMLString::transcode(e.getMessage());
    std::cerr << "Error during Xerces initialization: " << message << std::endl;
    xercesc::XMLString::release(&message);
  }
    return 0;
}
