#ifndef REGISTERS_H
#define REGISTERS_H 

#include <string>
#include <vector>
#include <utility> 

#include "Aperture.h"
#include "Core.cpp"


namespace gv {

class Registers {
public:
  Registers() {};
  Aperture operator[](int index) const;
  void Add(Aperture aperture);
  void Setup(const std::string& line);
private:
  std::vector<std::pair<int, Aperture>> regs;
public:
};


}


#endif 
