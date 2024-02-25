#ifndef APERTURE_H
#define APERTURE_H 

#include <sstream> 
#include <iostream>
#include <regex>
#include <string>

#include "Cords.h" 
#include "Core.cpp"

namespace gv {
enum REG_TYPE {
  CIRCLE = 0,
  RECTANGLE = 1,
  POLYGON = 2,
  OBROUND = 3
};


class Aperture {
  public:
    Aperture() : type(CIRCLE) , pos(0, 0) {}
    Aperture(REG_TYPE tp, double x, double y) : type(tp), pos(x, y) {}   
    Aperture(REG_TYPE tp, double x, double y, int i) : type(tp), pos(x, y), index(i) {}
    
    void Setup(const std::string& line);

    REG_TYPE type;
    Cords pos;
    int index;

    bool operator==(const gv::Aperture& obj) const; 

#ifdef gvDEBUG
  std::string Debug();
#endif

};

}

#endif 