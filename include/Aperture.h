#include "Expression.h"
#include "Cords.h"

namespace gv {

enum SHAPE {
  RECT = 0,
  CIRCLE = 1,
  POLYGON = 2,
  OBROUND = 3
};

class Aperture : public gv::Expression {
  SHAPE shape;
  Cords size;
};

}
