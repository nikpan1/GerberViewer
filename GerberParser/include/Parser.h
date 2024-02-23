#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <string>
#include <regex>

#include "Core.cpp"
#include "Settings.h"
#include "Registers.h" 

#include "Instructions/Instruction.h"
#include "Instructions/DCodes/MoveInstruction.h" 
#include "Instructions/DCodes/DrawInstruction.h" 
#include "Instructions/DCodes/FlashInstruction.h" 
#include "DeprecatedExpression.h"


namespace gv {

class Parser {
public:
  Parser(const std::string& FILENAME);
  gv::Settings _settings;
  std::string Run();
private:
  std::ifstream input;
  std::vector<Instruction> output;
  
  void ParseLine(const std::string& line);
  void ParseSettings(const std::string& line); 

  int getX(const std::string& line);
  int getY(const std::string& line);
  int getD(const std::string& line); 


public:
  std::vector<Instruction>& Parse();  
  gv::Registers _registers;
};

}

#endif


