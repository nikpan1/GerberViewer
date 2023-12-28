#include <iostream>

// ANSI escape codes for text color
#define RED_TEXT "\033[1;31m"
#define RESET_TEXT "\033[0m"

#define gdASSERT(condition, message) \
  do { \
    if (!(condition)) { \
      std::cout << RED_TEXT << message << RESET_TEXT << std::endl; \
    } \
  } while (false)


#define gdEXCEPTION(message) \
  do { \
    std::cout << RED_TEXT << message << RESET_TEXT << std::endl; \
  } while(false)


#define gdPRINT(message) \
    do { \
        if (!(condition)) { \
            std::cout << message << RESET_TEXT << std::endl; \
        } \
    } while (false)


#define LOG(message) \
    do { \
        if (!(condition)) { \
            std::cout << message << RESET_TEXT << std::endl; \
        } \
    } while (false)

