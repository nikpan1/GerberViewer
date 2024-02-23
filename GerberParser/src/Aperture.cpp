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
  int start = 4, end = 4;
  while(isNumber(line[end])) end ++;
  
  index = std::stoi(line.substr(start, end - start));

  switch (line[end]) { 
    case 'C':
      type = CIRCLE;
      break;
    case 'R':
      type = RECTANGLE;
      break;
    case 'P':
      type = POLYGON;
      break;
    case 'O':
      type = OBROUND;
      break;
    default: 
      gvLOG("REG_TYPE NOT FOUND.");
  }
  
  if(type == CIRCLE) {
    start = 5;
    while(line[start] != ',') start ++;
    pos.x = std::stoi(line.substr(start + 1, line.size() - start - 3)); 
  }
  else if(type == RECTANGLE || type == OBROUND || type == CIRCLE) {
    start = 5;
    while(line[start] != ',') start ++;
    int X_pos = start;
    while(line[X_pos] != 'X') X_pos ++;

    pos.x = std::stoi(line.substr(start + 1, X_pos - 1 - start)); 
    pos.y = std::stoi(line.substr(X_pos + 1, line.size() - 2));   
  }

}

#ifdef gvDEBUG

std::string gv::Aperture::Debug() {
  std::ostringstream stream;
    stream << type << " " << index << " " << pos.x << " " << pos.y;

  const std::string result = stream.str();

  return result;
}

#endif

