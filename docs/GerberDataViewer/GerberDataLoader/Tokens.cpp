#include "Tokens.h"

Token::Token(TokenType _type, std::string _lexeme, std::string _literal,
             int _line) {
  type = _type;
  lexeme = _lexeme;
  literal = _literal;
  line = _line;
}

std::ostream &operator<<(std::ostream &s, const Token &obj) {
  s << "Token(" << obj.type << ", " << obj.lexeme << ", " << obj.literal << ","
    << obj.line << ")";
  return s;
}
