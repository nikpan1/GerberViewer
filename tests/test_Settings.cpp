#include <gtest/gtest.h>
#include "Settings.h"

TEST(GerberViewer, FSLA) {
    gv::Settings s;

    s.Setup("%FSLAX33Y33%");
    EXPECT_EQ(s.FSLA.x, 33.0);
    EXPECT_EQ(s.FSLA.y, 33.0);
    
    s.Setup("%FSLAX11Y44%");
    EXPECT_EQ(s.FSLA.x, 11.0);
    EXPECT_EQ(s.FSLA.y, 44.0);
}

TEST(GerberViewer, MO) {
    gv::Settings s;

    s.Setup("%MOMM*%");
    EXPECT_EQ(s.MO, gv::MM);
    s.Setup("%MOINCH*%");
    EXPECT_EQ(s.MO, gv::INCH);
}

TEST(GerberViewer, IP) {
    gv::Settings s;

    s.Setup("%IPPOS*%");
    EXPECT_EQ(s.IP, gv::POS);
    
    s.Setup("%IPNEG*%");
    EXPECT_EQ(s.IP, gv::NEG);
}

TEST(GerberViewer, MI) {
    gv::Settings s;
    
    s.Setup("%MIA0B0*%");
    EXPECT_EQ(s.MI.x, 0); 
    EXPECT_EQ(s.MI.y, 0);
}

TEST(GerberViewer, SF) {
    gv::Settings s;

    s.Setup("%SFA1.000B1.000*%");
    EXPECT_EQ(s.SF.x, 1.0);
    EXPECT_EQ(s.SF.y, 1.0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

