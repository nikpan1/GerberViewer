#include <string> 


bool lookAhead(const std::string& line, int index, const std::string& verb) {
  int pivot = 0;
  while (pivot != verb.size()) {
    if(line[index + pivot] != verb[pivot]) return false;
    pivot ++;
  }

  return true;
}

