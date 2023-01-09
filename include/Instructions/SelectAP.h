#ifndef SELECTAP_H
#define SELECTAP_H

#include <string>
#include "Settings.h"
#include "Instruction.h" 

// Example
// D10*

namespace gv {
  class SelectAP {
    public:
      SelectAP(const std::string& line) {
        Setup(line);        
      }
      void Execute(const gv::Settings setting) {
      }

    private:
      int ap_index;
      void Setup(const std::string& line) {
        ap_index = std::stoi(line.substr(1, line.size() - 2));
      }
  };
}

#endif 
