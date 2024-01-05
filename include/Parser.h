#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

#include "Core.cpp"
#include "Expression.h"
#include "Settings.h"
#include "Register.h" 

namespace gv {
#ifndef PARSER_H
#define PARSER_H

class Parser {
public:
  Parser(const std::string& FILENAME);
  gv::Settings setting;
private:
  std::ifstream input;
  Expression ParseLine(const std::string& line);
  std::vector<Expression> output;
public:
  std::vector<Expression>& Parse();  
  std::unordered_map<int, Register> registers;
};

#endif
}

