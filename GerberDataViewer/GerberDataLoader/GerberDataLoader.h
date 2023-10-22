#include <iostream>
#include <string>

class DataLoader {
public:
  DataLoader(std::string _content);
  std::string print();

private:
  std::string content;
};
