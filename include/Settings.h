#include <string>
#include "Cords.h" 
#include "Core.cpp"

namespace gv {

#ifndef SETTINGS_H
#define SETTINGS_H 

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
};


#endif 
}
