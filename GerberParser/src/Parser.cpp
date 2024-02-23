#include "Parser.h"
#include "Instructions/Instruction.h"


gv::Parser::Parser(const std::string& FILENAME) {
  input.open(FILENAME);
  
  gvASSERT(input.is_open(), "File is not opened.\n");
  output.clear();
}

int gv::Parser::getX(const std::string& line) {
  std::regex patternX("X[-0-9]+");
  std::smatch matches;
  bool found = std::regex_search(line, matches, patternX);
  if(!found) return -1;

  std::string temp = matches[0];
  
  if(temp.empty())
    gvLOG("Something unexpected is happening in gv::Parser::getX().");
  
  temp.erase(temp.begin());
  return std::stoi(temp);
}

int gv::Parser::getY(const std::string& line) {
  std::regex patternY("Y[-0-9]+");
  std::smatch matches;
  bool found = std::regex_search(line, matches, patternY);
  if(!found) return -1;
  
  std::string temp = matches[0];
  
  if(temp.empty())
    gvLOG("Something unexpected is happening in gv::Parser::getD().");
  
  temp.erase(temp.begin());
  return std::stoi(temp);
}

int gv::Parser::getD(const std::string& line) { 
  std::regex patternD("D[-0-9]+");
  std::smatch matches;
  bool found = std::regex_search(line, matches, patternD);
  if(!found) return -1;
  
  std::string temp = matches[0];  

  if(temp.empty())
    gvLOG("Something unexpected is happening in gv::Parser::getD().");
  
  temp.erase(temp.begin());
  return std::stoi(temp);
}


static bool Contains(const std::string& line, char c) {
  for(int i = line.size() - 1; i >= 0; i --) {
    if(line[i] == c) {
      return true;
    }
  }

  return false;
}
std::string gv::Parser::Run() {
  std::string created_path;
  auto parsed = Parse(); 


return created_path;
}

void gv::Parser::ParseLine(const std::string& line) {
  // analyze the first line
  // then depending on the rest add expreesion new 
  
  // G54
  // X...Y...D..
  // X...Y...
  // G01X...Y...D...
  // M02 
  
  if(line[0] == 'G') {
    // deprecated expression if
    // G...X...Y...D...

    // change settings if 
    // G... 
  }

  if(line[0] == 'X' || line[0] == 'Y' || line[0] == 'D') {
    auto X = gv::Parser::getX(line);
    auto Y = gv::Parser::getY(line);
    auto D = gv::Parser::getD(line);
    X = (X == -1) ? 0 : X;
    Y = (Y == -1) ? 0 : Y;
    D = (D == -1) ? 0 : _settings.last_used;
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

std::vector<gv::Instruction>& gv::Parser::Parse() {
  std::string line;

  gv::Settings _settingss; 
  
  // analyze Settings 
  while(std::getline(input, line) && line[0] == '%') {
    ParseSettings(line);
  }  
  gvLOG("SETST");
  // analyze movement instructions 
  do {
    ParseLine(line);
  } while(std::getline(input, line)); 


  return output;
}

