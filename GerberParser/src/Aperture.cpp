#include "Aperture.h"


bool isNumber(char c) {
  return c >= '0' && c <= '9';
}


bool gv::Aperture::operator==(const gv::Aperture& obj) const {
  return (obj.index == index) &&
    (obj.pos.x == pos.x) &&
    (obj.pos.y == pos.y) &&
    (obj.type == type);
}


bool gv::Aperture::Setup(const std::string& line) {
  if(line[1] != 'A' || line[3] != 'D') return true;
  
  std::regex patternCircle("%ADD[0-9]+C,[[0-9].]+*%");
  std::regex patternRect(R"(%ADD\d+R,([\d.]+)X([\d.]+)\*%)");

  std::smatch Cmatches;
  
  bool found = std::regex_search(line, Cmatches, patternCircle);
  if(found) {  // circle
    index = std::stoll(Cmatches[0]);
    pos.x = std::stoll(Cmatches[1]);
    pos.y = std::stoll(Cmatches[1]);
    

    return true;
  }

  std::smatch Rmatches;
  found = std::regex_search(line, Rmatches, patternRect);
  if(found) {  // rect
    index = std::stoll(Rmatches[0]);
    pos.x = std::stoll(Rmatches[1]);
    pos.y = std::stoll(Rmatches[2]);

  gvLOG("PATTERN:" << index << " {" << pos.x << ", " << pos.y)
    return true;
  }

  // polygon obround
  std::regex patternID("%ADD([0-9]+)(R|C|O|P)");
  std::smatch IDmatches;
  found = std::regex_search(line, IDmatches, patternID);
  
  if(!found) return false;
  else index = std::stoll(IDmatches[1]);
  
  return true;
}

#ifdef gvDEBUG

std::string gv::Aperture::Debug() {
  std::ostringstream stream;
    stream << type << " " << index << " " << pos.x << " " << pos.y;

  const std::string result = stream.str();

  return result;
}

#endif

