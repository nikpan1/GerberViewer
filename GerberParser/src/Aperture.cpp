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


void gv::Aperture::Setup(const std::string& line) {
  if(!(line[1] == 'A' && line[3] == 'D')) return;
  
  std::regex patternCircle("(%ADD([0-9]+)C,([[0-9].]+)*%)");
  std::regex patternRect("(%ADD[0-9]+R,([[0-9].]+)X([[0-9].]+)*%)");

  std::smatch Cmatches;
  
  bool found = std::regex_search(line, Cmatches, patternCircle);
  if(found) {  // circle
  gvLOG("\n");
   for(auto a: Cmatches) gvLOG("A-"<< a); 
    index = std::stoll(Cmatches[0]);
    pos.x = std::stoll(Cmatches[1]);
    pos.y = std::stoll(Cmatches[1]);

    return;
  }

  std::smatch Rmatches;
  found = std::regex_search(line, Rmatches, patternRect);
  if(found) {  // rect
    index = std::stoll(Rmatches[0]);
    pos.x = std::stoll(Rmatches[1]);
    pos.y = std::stoll(Rmatches[2]);

    return;
  }

  // polygon obround
  std::regex patternID("%ADD([0-9]+)(R|C|O|P)");
  std::smatch IDmatches;
  found = std::regex_search(line, IDmatches, patternID);
  
  for(auto a : IDmatches) gvLOG("FD" << a);
  if(!found) index = 0;
  else index = std::stoll(IDmatches[1]);
}

#ifdef gvDEBUG

std::string gv::Aperture::Debug() {
  std::ostringstream stream;
    stream << type << " " << index << " " << pos.x << " " << pos.y;

  const std::string result = stream.str();

  return result;
}

#endif

