#ifndef MOVE_DCODE_INSTRUCTION_H
#define MOVE_DCODE_INSTRUCTION_H

#include "Instructions/DCodes/DCodesInstruction.h" 

namespace gv {
  class MoveInstruction : public DcodesInstruction {
    public:
      MoveInstruction() {}
      std::string label="FLASH_DCODE";
      
      void Execute(const Settings& settings) override {
        gvLOG("Executing default Instruction function.");
      }
  };
}

#endif
