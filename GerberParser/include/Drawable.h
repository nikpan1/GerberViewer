#include "Core.cpp"

namespace gv {

#ifndef DRAWABLE_H 
#define DRAWABLE_H 

class Drawable {
public:
  virtual void draw() const {
    gvLOG("DRAWABLE");
  } 
};

#endif

}
