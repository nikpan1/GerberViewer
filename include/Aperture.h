#include "Expression.h"
#include "Core.cpp"

namespace gv {

enum SHAPE {
  RECT = 0,
  CIRCLE = 1,
  POLYGON = 2,
  OBROUND = 3
};

class Aperture : public gv::Expression {
  SHAPE shape;
  cord size;
};

}
