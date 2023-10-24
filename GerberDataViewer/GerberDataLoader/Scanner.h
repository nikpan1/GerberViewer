#include "Tokens.h"
#include <string>
#include <vector>

class Scanner {
public:
  Scanner(std::string _source);

private:
  std::string source;
  std::vector<Token> tokens;
};
