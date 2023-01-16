#include <sstream> 

#include "Cords.h" 
#include "Core.cpp"
#include "strManipulation.cpp"

#ifndef SETTINGS_H
#define SETTINGS_H 

namespace gv {

enum MO_TYPE {
  MM = 0,
  INCH = 1
};

enum IP_TYPE {
  POS = 0,
  NEG = 1
};

class Settings {
public:
  Settings() { }
  void Setup(const std::string& line);

  Cords FSLA;
  Cords SF; // X - A,  Y - B 
  MO_TYPE MO;
  Cords MI;
  IP_TYPE IP;

#ifdef gvDEBUG 
  const std::string Debug();
#endif 
};


}

#endif 
