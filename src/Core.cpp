#include <iostream>
#include <cassert>

#define RED_TEXT "\033[1;31m"
#define GREEN_TEXT "\033[1;32m"
#define RESET_TEXT "\033[0m"


#ifdef gvDEBUG

#define gvASSERT(condition, message) \
  do { \
    if (!(condition)) std::cerr << RED_TEXT << "ASSERTION | " << RESET_TEXT << message << '\n'; \
    assert(condition);\
  } while (false)


#define gvEXCEPTION(message) \
  do { \
    std::cerr << RED_TEXT << message << RESET_TEXT << '\n'; \
  } while(false)

#define gvLOG(message) std::cout << GREEN_TEXT << "   LOG    | " << RESET_TEXT << message << '\n'; 

#endif 


#ifdef gvRELEASE

#define gvASSERT(condition, message)
#define gvEXCEPTION(message) 
#define gvLOG(message) 
 
#endif


struct cord {
  double x; // @TODO change to union?
  double y;
};

