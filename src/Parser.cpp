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
  
  gv::Settings setting;

  switch(line[0]) {
    case '%':  // it's a setting  
      if(line.substr(0, 3) == "%TF") ; // ignore
      else if(line.substr(0, 4) == "%FSLA")
        setting.fileSpecification = FILE_SPEC{cord{1}, cord{1}};
      else if(line.substr(0, 3) == "%MO") 
        setting.unit = line[3] == 'M' ? MM : IN;
      else if(line.substr(0, 3) == "%LP")
        setting.polarity = line[3] == 'D' ? dark : bright;
      else;
      break;
    case 'X':
      break;
    case 'Y':
      break;
    case 'G':
      break;
    case 'D':
      break;
  }
 
  return result;
}

std::vector<gv::Expression>& gv::Parser::Parse() {
  std::string line;

  while(std::getline(input, line)) {
    output.push_back(ParseLine(line));
  }
  
  return output;
}

