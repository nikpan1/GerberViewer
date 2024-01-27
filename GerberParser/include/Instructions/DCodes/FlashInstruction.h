#ifndef FLASH_DCODE_INSTRUCTION_H
#define FLASH_DCODE_INSTRUCTION_H

#include "Instructions/DCodes/DCodesInstruction.h" 

namespace gv {
  class FlashInstruction : public DcodesInstruction {
    public:
      FlashInstruction() {}
      std::string label="FLASH_DCODE";
      
      void Execute(const Settings& settings) override {
        gvLOG("Executing default Instruction function.");
      }
  };
}

#endif
