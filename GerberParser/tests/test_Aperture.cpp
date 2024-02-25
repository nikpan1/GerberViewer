#include "Aperture.h" 
#include <gtest/gtest.h>

TEST(GerberViewer, Aperture_type) {
  gv::Aperture ap;
  
  ap.Setup("%ADD11C,1.32100*%");
  EXPECT_EQ(ap.type, gv::CIRCLE);
 
  ap.Setup("%ADD11R,1.32100X1.0000*%");
  EXPECT_EQ(ap.type, gv::RECTANGLE);
}

TEST(GerberViewer, Aperture) {
  gv::Aperture ap;
  // type x y index 


  ap.Setup("%ADD11C,1.32100*%");
  EXPECT_EQ(gv::Aperture(gv::CIRCLE, 1.321, 1.321, 11), ap);

  ap.Setup("%ADD910C,0.0110*%");
  EXPECT_EQ(gv::Aperture(gv::CIRCLE, 0.011, 0.011, 910), ap);

  // ---

  ap.Setup("%ADD61R,0.01100X6.47520*%");
  EXPECT_EQ(gv::Aperture(gv::RECTANGLE, 0.011, 6.4752, 61), ap);

  ap.Setup("%ADD12R,0.10000X1.10000*%");
  EXPECT_EQ(gv::Aperture(gv::RECTANGLE, 0.1, 1.1, 12), ap);

  // ---
  /*
  ap.Setup("%ADD910C,0.0110*%");
  EXPECT_EQ(gv::Aperture(gv::CIRCLE, 0.011, 0, 910), ap);

  ap.Setup("%ADD910C,0.0110*%");
  EXPECT_EQ(gv::Aperture(gv::CIRCLE, 0.011, 0, 910), ap);

  ap.Setup("%ADD910C,0.0110*%");
  EXPECT_EQ(gv::Aperture(gv::CIRCLE, 0.011, 0, 910), ap);
  */


}



