#include "Tokens.h"
#include <string>
#include <vector>

class Scanner {
public:
  Scanner(std::string _source);
  std::vector<Token> scanTokens();

private:
  std::string source;
  std::vector<Token> tokens;

  int start = 0, current = 0, line = 1;

  void scanToken();
  bool isAtEnd();

  char advance();
  void addToken(TokenType type);
  void addToken(TokenType type, std::string literal);

  bool match(char expected);
  bool peek();
};
