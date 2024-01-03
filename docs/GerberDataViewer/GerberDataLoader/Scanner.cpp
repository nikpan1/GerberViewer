#include "Scanner.h"

std::vector<Token> Scanner::scanTokens() {
  while (!isAtEnd()) {
    start = current;
    scanToken();
  }

  Token tk(ENDF, "", "", line);
  tokens.push_back(tk);
  return tokens;
}
Scanner::Scanner(std::string _source) { source = _source; }

bool Scanner::isAtEnd() { return current >= source.size(); }

char Scanner::advance() { return source[current++]; };

void Scanner::scanToken() {
  char c = advance();

  switch (c) {
  case '(':
    addToken(LEFT_PAREN);
    break;
  case ')':
    addToken(RIGHT_PAREN);
    break;
  case '{':
    addToken(LEFT_BRACE);
    break;
  case '}':
    addToken(RIGHT_BRACE);
    break;
  case ',':
    addToken(COMMA);
    break;
  case '.':
    addToken(DOT);
    break;
  case '-':
    addToken(MINUS);
    break;
  case '+':
    addToken(PLUS);
    break;
  case ';':
    addToken(SEMICOLON);
    break;
  case '*':
    addToken(STAR);
    break;
  default:
    std::cerr << "Unknown grammar";
  }
}

void Scanner::addToken(TokenType type) { addToken(type, ""); }

void Scanner::addToken(TokenType type, std::string literal) {
  auto value = source.substr(start, current);
  Token tk(type, value, literal, line);
  tokens.push_back(tk);
}

bool Scanner::match(char expected) {
  if (isAtEnd())
    return false;
  if (source[current] != expected)
    return false;

  current++;
  return true;
}

bool Scanner::peek() {
  if (isAtEnd())
    return '/0';
  else
    return source[current];
}
