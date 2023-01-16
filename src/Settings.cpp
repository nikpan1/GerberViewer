#include "Settings.h"


void gv::Settings::Setup(const std::string& line) {
  std::string sub = line.substr(1, 2);

  if("FS" == sub) {
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


std::ostream& operator<<(std::ostream& os, const gv::Settings& obj) {
  os << "[ SETTINGS ]\n";
  os << "FSLA = (" << obj.FSLA.x << ", " << obj.FSLA.y << ")\n";
  os << "SF = (" << obj.SF.x << ", " << obj.SF.y << ")\n";
  os << "MO = " << obj.MO << "\n";
  os << "MI = (" << obj.MI.x << ", " << obj.MI.y << ")\n";
  os << "IP = " << obj.IP << "\n";

  return os; 
}

#ifdef gvDEBUG

const std::string gv::Settings::Debug() {
  std::ostringstream stream;
    stream << 
    FSLA.x << " " << FSLA.y << " " << SF.x << 
    " " << SF.y << " " << MO << " " << MI.x <<
    " " << MI.y << " " << IP;
  
  const std::string result = stream.str();

  return result;
}

#endif 
