#include <iostream> 
#include "Parser.h"
#include "Core.cpp"

int main(int argc, char** argv) {
  std::cout << "Starting the main.cpp.\n";
  gvASSERT(argc != 2, "Wrong amount of inputs.\n");
  
  std::string str = argv[1];
  auto v = gd::Parser(str);
  
  return 0;
}

