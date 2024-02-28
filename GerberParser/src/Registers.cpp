#include "Registers.h"


gv::Aperture gv::Registers::operator[](int index) const {
  for(auto pr : regs) {
    if(pr.first == index) {
      return pr.second;
    }
  }

  gvLOG("Warning, Registers");
  return gv::Aperture(gv::CIRCLE, 1, 1);
}

void gv::Registers::Add(gv::Aperture aperture) {
  regs.push_back(std::make_pair(aperture.index, aperture)); 
}

gv::Aperture gv::Registers::Get(int id) {
  for(auto val : regs) {
    if(val.first == id) return val.second;
  }
  return regs[0].second;
}

void gv::Registers::Setup(const std::string& line) {
  gv::Aperture ap; 
  bool success = ap.Setup(line);
  if(success) Add(ap);
}

std::string gv::Registers::Debug() {
  std::string strs=" ";
  for(auto reg : regs) {
    strs += reg.second.Debug();
    strs += "\n";
  }

  return strs;
}



