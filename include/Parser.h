#include <iostream>
#include <fstream>
#include <vector>
#include "Expression.h"


namespace gd {

class Parser {
public:
  Parser(const std::string& FILENAME);
private:
  std::ifstream input;
  Expression ParseLine(const std::string& line);
  std::vector<Expression> output;
public:
  std::vector<Expression>& Parse();  
};

}

