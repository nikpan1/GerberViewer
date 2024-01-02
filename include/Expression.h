// base class of every expression
#include <iostream>


namespace gv {

class Expression {
public:
  friend std::ostream& operator<<(std::ostream& os, const Expression& expr);
};

}
