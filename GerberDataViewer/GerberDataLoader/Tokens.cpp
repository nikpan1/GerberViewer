#include <iostream>
#include <string>
#include <vector>

enum TokenType {

  // single logic tokens
  X_CORD,
  Y_CORD,
  X_INTERP,
  Y_INTERP,
  PERCENT,

  // one character tokens
  SELECT, // D10*

  // two character tokens
  DEFINE,
  SET,

  // Literals
  IDENTIFIER,
  STR,
  NUM,
  COMMENT,

  // special tokens
  // EOF ?
  NIL,
};

class Token {
  TokenType type;

  std::string lexeme;
  std::string literal; // needs to be optimzed later on

  int line;

  Token(TokenType _type, std::string _lexeme, std::string _literal, int _line) {
    type = _type;
    lexeme = _lexeme;
    literal = _literal;
    line = _line;
  }

  friend std::ostream &operator<<(std::ostream &s, const Token &obj) {
    s << "Token(" << obj.type << ", " << obj.lexeme << ", " << obj.literal
      << "," << obj.line << ")";
    return s;
  }
};
