#include "Parser.h"
#include <iostream> 


int main(int argc, char** argv) {
  if(argc != 2) std::cerr << "Wrong amount of inputs.\n";
  
  std::string str = argv[1];
  auto v = gd::Parser(str);
  
  return 0;
}

