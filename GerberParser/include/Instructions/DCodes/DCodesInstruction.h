// DCODE BASE CLASS 

#ifndef DCODE_INSTRUCTION_H
#define DCODE_INSTRUCTION_H

#include "Instructions/Instruction.h" 

namespace gv {
  class DcodesInstruction : public Instruction {
    public:
      DcodesInstruction() {}
      std::string label;
      
      void Execute(const Settings& settings) override {
        gvLOG("Executing default Instruction function.");
      }
  };
}

#endif
