#ifndef EOF_INSTRUCTION_H
#define EOF_INSTRUCTION_H

#include "Instruction.h" 

namespace gv {
  class EOFInstruction : public gv::Instruction {
    public:
      EOFInstruction() {}
      std::string label="EOF";
      
      virtual void Execute(const Settings& settings) {
        gvLOG("ENDOFFILE");
      }
  };
}

#endif
