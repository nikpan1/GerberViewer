#ifndef DRAWABLE_H 
#define DRAWABLE_H 

#include "Core.cpp"

namespace gv {

class Drawable {
public:
  virtual void draw() const {
    gvLOG("DRAWABLE");
  } 
};

}

#endif
