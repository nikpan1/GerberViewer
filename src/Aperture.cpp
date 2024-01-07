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
  int start = 4, end = 5;
  while(isNumber(line[end + 1])) end ++;
  gv::Aperture ap;
  
  ap.index = std::stoi(line.substr(start, end - start));

  gv::REG_TYPE tp;
  switch (line[end + 1]) { 
    case 'C':
      tp = CIRCLE;
      break;
    case 'R':
      tp = RECTANGLE;
      break;
    case 'P':
      tp = POLYGON;
      break;
    case 'O':
      tp = OBROUND;
      break;
    default: 
      gvLOG("REG_TYPE NOT FOUND.");
  }
  
  ap.type = tp;
  
  if(tp == CIRCLE) {
    start = 5;
    while(line[start] != ',') start ++;
    ap.pos.x = std::stoi(line.substr(start + 1, line.size() - start - 3)); 
  }
  else if(tp == RECTANGLE) {

    start = 5;
    while(line[start] != ',') start ++;
    int X_pos = start;
    while(line[X_pos] != 'X') X_pos ++;

    ap.pos.x = std::stoi(line.substr(start + 1, X_pos - 1 - start)); 
    ap.pos.y = std::stoi(line.substr(X_pos + 1, line.size() - 2));   
  }

}
