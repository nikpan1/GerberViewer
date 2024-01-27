// BASE CLASS 

#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "Core.cpp"
#include <string>  
#include "Cords.h"
#include "Settings.h" 

namespace gv {
  class Instruction {
    public:
      Instruction() {}
      std::string label;
      
      virtual void Execute(const Settings& settings) {
        gvLOG("Executing default Instruction function.");
      }
  };
}

#endif
