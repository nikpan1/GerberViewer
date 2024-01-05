#include "Cords.h" 


namespace gv {
#ifndef APERTURE_H
#define APERTURE_H 

enum REG_TYPE {
  CIRCLE = 0,
  POLYGON = 1
};


class Aperture {
  public:
    Aperture() : type(CIRCLE) , pos(0, 0) {}
    Aperture(REG_TYPE tp, double x, double y) : type(tp), pos(x, y) {}   

    REG_TYPE type;
    Cords pos;

};

#endif 
}
