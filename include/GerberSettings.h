#include "Cords.h"

namespace gv {

enum UNIT {
  MM = 0, // millimeters
  IN = 1  // inches
};

enum POLARITY {
  dark = 0,
  bright = 1
};

// FS = '%' ('FS' 'LA' 'X' coord_digits 'Y' coord_digits) '*%';
// coord_digits = /[1-6][56]/;  
struct FILE_SPEC {
public:
  Cords integers;
  Cords fractionals;
};


class Settings {
public:
  UNIT unit;
  Cords fileSpecification;

  POLARITY polarity;
};


}
