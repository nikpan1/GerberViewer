#ifndef DRAWABLE_H 
#define DRAWABLE_H 

#include "Core.cpp"
#include <SFML/Graphics/Image.hpp>

namespace gv {

class Drawable {
public:
  virtual void draw(sf::Image& image) const {
    gvLOG("DRAWABLE");
  } 
};

}

#endif
