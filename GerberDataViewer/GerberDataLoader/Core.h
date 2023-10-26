
enum TokenType {

  // single logic tokens
  X_CORD,
  Y_CORD,
  X_INTERP,
  Y_INTERP,
  PERCENT,

  // one character tokens
  LEFT_PAREN,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  SLASH,
  STAR,
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
  ENDL,
  ENDF,
};
