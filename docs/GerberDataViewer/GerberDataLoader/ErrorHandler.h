#include <iostream>
#include <Core.h>

class errHandler {
  bool hadError = false;

  static void error(int line_num, std::string line) {
    hadError = true;
    std::cerr << "Error bellow [" << line_num << "]\n | " << line << '\n';
  }

  static void handle() {
    hadError = false;
  }
  
};
