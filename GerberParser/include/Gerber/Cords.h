#include <string> 

namespace gv {
#ifndef CORDS_H
#define CORDS_H


class Cords {
public: 
  int x;
  int y;

  Cords() : x(0), y(0) {}
  Cords(int _x, int _y) : x(_x), y(_y) {} 
  

  static double GetData(char c, const std::string& line);
 
  static double GetX(const std::string& line);
  static double GetY(const std::string& line);
};

#endif 

}
