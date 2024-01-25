#include "Parser.h"


gv::Parser::Parser(const std::string& FILENAME) {
  return;
  input.open(FILENAME);
  
  gvASSERT(!input.is_open(), "File is not opened.\n");
  output.clear();
}

static bool Contains(const std::string& line, char c) {
  for(int i = line.size() - 1; i >= 0; i --) {
    if(line[i] == c) {
      return true;
    }
  }

  return false;
}


void gv::Parser::ParseLine(const std::string& line) {
  // analyze the first line
  // then depending on the rest add expreesion new 
  
  // G54
  // X...Y...D..
  // X...Y...
  // G01X...Y...D...
  // M02 
  
  if(line[0] == 'G') { // G54 
  }
  else if(line[0] == 'X' || line[1] == 'Y') {
    if(Contains(line, 'D')) { // X...Y...D..
    
    }
    else { // X...Y...
      
    }
  }
  else if(line.substr(0, 3) == "M02") {
  
  }
  else {
    gvLOG("NOT FOUND | " << line);
  }
}

void gv::Parser::ParseSettings(const std::string& line) {
  // depending on the content, setup settings 

  // FSLA
  // MM/INCH
  // SFA
  // MIA
  // IPPOS
  // LPD ?

  _settings.Setup(line);

  // ADD aperture, store in registers

  _registers.Setup(line);
}

std::vector<gv::Expression>& gv::Parser::Parse() {
  std::string line;

  gv::Settings _settingss; 
  
  // analyze Settings 
  while(std::getline(input, line) && line[0] == '%') {
    ParseSettings(line);
  }  

  // analyze movement instructions 
  do {
    ParseLine(line);
  } while(std::getline(input, line)); 


  return output;
}

