#include <unordered_map> 
#include "Aperture.h"
#include "Core.cpp"

namespace gv {
#ifndef REGISTERS_H
#define REGISTERS_H 


class Registers {
public:
  Registers() {};
  Aperture operator[](int index) const;

private:
  std::unordered_map<int, Aperture> regs;
};

#endif 

}
