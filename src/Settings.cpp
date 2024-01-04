#include "Settings.h"


void gv::Settings::Setup(const std::string& line) {
  std::string sub = line.substr(1, 2);

  if("FSLA" == sub) {
    FSLA.x = gv::Cords::GetX(line);
    FSLA.y = gv::Cords::GetY(line);
  }
  else if("SF" == sub) {
    SF.x = gv::Cords::GetData('A', line);
    SF.y = gv::Cords::GetData('B', line);
  }
  else if("MO" == sub) {
    MO = ('M' == line[3]) ? MM : INCH; 
  }
  else if("MI" == sub) {
    MI.x = gv::Cords::GetData('A', line);
    MI.y = gv::Cords::GetData('B', line);
  }
  else if("IP" == sub) {
    IP = (line[3] == 'P') ? POS : NEG;
  }
  else {
  gvLOG("NEW SETUP: " + line);
  }
}
