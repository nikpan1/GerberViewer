#include <iostream> 
#include "Parser.h"

int main(int argc, char** argv) {
  std::cout << "Starting the main.cpp.\n";
  if(argc != 2) std::cerr << "Wrong amount of inputs.\n";
  
  std::string str = argv[1];
  auto v = gd::Parser(str);
  
  return 0;
}

