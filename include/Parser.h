#ifndef PARSER_H
#define PARSER_H


#include <fstream>
#include <vector>
#include <string>

#include "Core.cpp"
#include "Expression.h"
#include "Settings.h"
#include "Registers.h" 

namespace gv {

class Parser {
public:
  Parser(const std::string& FILENAME);
  gv::Settings _settings;

private:
  std::ifstream input;
  std::vector<Expression> output;
  
  void ParseLine(const std::string& line);
  void ParseSettings(const std::string& line); 


public:
  std::vector<Expression>& Parse();  
  gv::Registers _registers;
};

}

#endif


