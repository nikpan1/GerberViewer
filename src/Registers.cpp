#include "Registers.h"

gv::Aperture gv::Registers::operator[](int index) const {
  gvASSERT(regs.count(index) <= 0);
  return regs[index];
}
