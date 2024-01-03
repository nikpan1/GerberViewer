#include "GerberDataLoader.h"

void DataLoader::run(std::string source) {
  Scanner *scanner = new Scanner(source);
  std::vector<Token> tokens = scanner.scanTokens();

  for (Token token : tokens) {
    std::cout << token;
  }
}
