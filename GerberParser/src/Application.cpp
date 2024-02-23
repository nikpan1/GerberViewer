#include "Parser.h"
#include "Core.cpp"


int main(int argc, char** argv) {
  gvLOG("Starting the main.cpp.")
  gvASSERT(argc == 2, "Wrong amount of inputs.");

  std::string str = argv[1];
  
  auto v = gv::Parser(str);
  auto path = v.Run();
  gvLOG(path);

  return 0;
}

