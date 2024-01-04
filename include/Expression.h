#include "Core.cpp"
#include "Drawable.h" 

namespace gv {

#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression : public Drawable {
  public:
    Expression() {}

    friend std::ostream& operator<<(std::ostream& os, const Expression& obj); 
};

#endif 
}
