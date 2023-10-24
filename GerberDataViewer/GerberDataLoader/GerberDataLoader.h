#include <iostream>
#include <string>
#include <vector>

class DataLoader {
public:
  DataLoader(std::string _content);

  std::string print();

private:
  std::string content;

  void run(std::string source);
};
