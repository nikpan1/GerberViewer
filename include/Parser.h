#include <fstream>
#include <vector>
#include <string>

#include "Core/Core.cpp"
#include "Expression.h"


namespace gv {

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

