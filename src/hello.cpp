// a simple hello world program written in c++

#include <iostream>
// #include <xercesc/util/XercesDefs.hpp>
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XercesVersion.hpp> // For Xerces-C++ version macros
#include <xercesc/util/XMLString.hpp> // Required for XMLString class

int main() {
  std::cout << "hello world cpp" << std::endl;

  try {
    // Initialize Xerces-C++
    xercesc::XMLPlatformUtils::Initialize();

    // Example usage of XMLString and XercesDefs (XMLSize_t)
    const char* sample = "Hello, Xerces!";
    XMLCh* wideChar = xercesc::XMLString::transcode(sample);

    // Use XERCES_SIZE_T for string length calculation
    XERCES_SIZE_T length = xercesc::XMLString::stringLen(wideChar); // Use XERCES_SIZE_T here
    std::cout << "Wide-char string length (XERCES_SIZE_T): " << length << std::endl;

    char* backToNarrow = xercesc::XMLString::transcode(wideChar);
    std::cout << "Back to narrow string: " << backToNarrow << std::endl;

    // Clean up
    xercesc::XMLString::release(&wideChar);
    xercesc::XMLString::release(&backToNarrow);

    // Terminate Xerces-C++
    xercesc::XMLPlatformUtils::Terminate();
  } 
  catch (const xercesc::XMLException& e) {
    char* message = xercesc::XMLString::transcode(e.getMessage());
    std::cerr << "Error during Xerces initialization: " << message << std::endl;
    xercesc::XMLString::release(&message);
  }
  return 0;
}
