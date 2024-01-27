#ifndef DRAWER_H
#define DRAWER_H

#include "Parser.h" 

namespace gv {
  class Drawer {
    public: 
      Drawer(const gv::Parser parser);
      
      // it should return maybe a filepath
      void Draw();
    private:
      gv::Parser _parser;

  };

}

#endif 
