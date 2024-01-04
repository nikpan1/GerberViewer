#include "GerberSettings.h"

void gv::ParseSettings(const std::string& line) {
  //... switch case 
}

gv::Settings(std::ifstream input) {
  std::string line;
  
  while(std::getline(input, line) && line[0] == '%') {
    ParseSettings(line);
  }
}

