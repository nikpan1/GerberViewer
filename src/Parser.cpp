#include "Parser.h"


gv::Parser::Parser(const std::string& FILENAME) {
  return;
  input.open(FILENAME);
  
  gvASSERT(!input.is_open(), "File is not opened.\n");
  output.clear();
}


gv::Expression gv::Parser::ParseLine(const std::string& line) {
  // analyze the first line
  // then depending on the rest add expreesion new 
 
  gv::Expression result;

 



  return result;
}

std::vector<gv::Expression>& gv::Parser::Parse() {
  std::string line;

  gv::Settings settings(input);
    

  while(std::getline(input, line)) {
    output.push_back(ParseLine(line));
  }
  
  return output;
}

