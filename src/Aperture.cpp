#include "Aperture.h"


bool isNumber(char c) {
  return c >= '0' && c <= '9';
}


void gv::Aperture::Setup(const std::string& line) {
  int start = 4, end = 5;
  while(isNumber(line[end + 1])) end ++;
  gv::Aperture ap;
  
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
  }
  
  ap.type = tp;

  int x_pos = 6;
 
  while(line[x_pos] != 'X' && x_pos < line.size()) x_pos ++;
  
  if(x_pos >= line.size()) {
    //ap.pos.x = std::stoi(line, end + 3, line.size() - 1 - (end + 3) - 2);  
  }
  else {
  // %ADD12R,0.6X0.6*%
  // %ADD11C,0.6*%

  }
}
