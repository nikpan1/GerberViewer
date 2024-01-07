#include "Registers.h"


gv::Aperture gv::Registers::operator[](int index) const {
  for(auto pr : regs) {
    if(pr.first == index) {
      return pr.second;
    }
  }

  return gv::Aperture(gv::CIRCLE, 1, 1);
}

void gv::Registers::Add(gv::Aperture aperture) {
  regs.push_back(std::make_pair(aperture.index, aperture)); 
}


void gv::Registers::Setup(const std::string& line) {
}




