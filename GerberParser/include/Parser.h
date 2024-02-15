#ifndef PARSER_H
#define PARSER_H

#include <fstream>
#include <vector>
#include <string>

#include "Core.cpp"
#include "Settings.h"
#include "Registers.h" 

#include "Instructions/Instruction.h"
#include "Instructions/DCodes/MoveInstruction.h" 
#include "Instructions/DCodes/DrawInstruction.h" 
#include "Instructions/DCodes/FlashInstruction.h" 



namespace gv {

class Parser {
public:
  Parser(const std::string& FILENAME);
  gv::Settings _settings;

private:
  std::ifstream input;
  std::vector<Instruction> output;
  
  void ParseLine(const std::string& line);
  void ParseSettings(const std::string& line); 


public:
  std::vector<Instruction>& Parse();  
  gv::Registers _registers;
};

}

#endif


