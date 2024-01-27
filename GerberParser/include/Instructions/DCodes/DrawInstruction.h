#ifndef DRAW_DCODE_INSTRUCTION_H
#define DRAW_DCODE_INSTRUCTION_H

#include "Instructions/DCodes/DCodesInstruction.h" 

namespace gv {
  class DrawInstruction : public DcodesInstruction {
    public:
      DrawInstruction() {}
      std::string label="DRAW_DCODE";
      
      void Execute(const Settings& settings) override {
        gvLOG("Executing default Instruction function.");
      }
  };
}

#endif
