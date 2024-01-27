#include "Cords.h"

bool isNum(char c) {
  return (c >= '0' && c <= '9');
}


double gv::Cords::GetX(const std::string& line) {
  int i = 0;
  while (line[i] != 'X') {
    if(i >= line.size()) {
      return -1;    
    }

    i ++;
  }

  i ++;
  
  int start = i;
  while(isNum(line[i])) {
    if(i >= line.size()) {
      break;
    }

    i ++;
  }

  return std::stoll(line.substr(start, i - start));

}

double gv::Cords::GetY(const std::string& line) {
  int i = 0;
  while (line[i] != 'Y') {
    if(i >= line.size()) {
      return -1;    
    }

    i ++;
  }

  i ++;
  
  int start = i;
  while(isNum(line[i])) {
    if(i >= line.size()) {
      break;
    }

    i ++;
  }

  return std::stoll(line.substr(start, i - start));


}

double gv::Cords::GetData(char c, const std::string& line) {
  int i = 0;
  while (line[i] != c) {
    if(i >= line.size()) {
      return -1;    
    }

    i ++;
  }

  i ++;
  
  int start = i;
  while(isNum(line[i])) {
    if(i >= line.size()) {
      break;
    }

    i ++;
  }

  return std::stoll(line.substr(start, i - start));
}

