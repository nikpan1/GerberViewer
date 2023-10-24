#include "Core.h"
#include <iostream>
#include <string>

class Token {
  TokenType type;

  std::string lexeme;
  std::string literal; // needs to be optimzed later on

  int line;

  Token(TokenType _type, std::string _lexeme, std::string _literal, int _line);
  friend std::ostream &operator<<(std::ostream &s, const Token &obj);
};
