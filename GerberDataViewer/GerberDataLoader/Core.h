
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
