#include "Parser.h"


gd::Parser::Parser(const std::string& FILENAME) {
  return;
  input.open(FILENAME);
  
  if(!input.is_open()) {
    std::cerr << "File not opened.\n";
  }
  
  output.clear();
}

gd::Expression gd::Parser::ParseLine(const std::string& line) {
  gd::Expression result;
  return result;
}

std::vector<gd::Expression>& gd::Parser::Parse() {
  std::string line;

  while(std::getline(input, line)) {
    output.push_back(ParseLine(line));
  }
  
  return output;
}

