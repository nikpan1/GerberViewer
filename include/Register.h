

namespace gv {

#ifndef REGISTER_H
#define REGISTER_H 

enum REG_TYPE {
  CIRCLE = 0,
  POLYGON = 1
};

class Register {

public:
  REG_TYPE type;
  double x;
  double y;

  Register(REG_TYPE tp, double _x, double _y) : type(tp), x(_x), y(_y) {}   

};


#endif 

}
