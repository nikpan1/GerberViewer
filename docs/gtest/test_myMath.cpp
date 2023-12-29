#include <gtest/gtest.h>
#include "myMath.cpp"

TEST(AddFunction, PositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
    EXPECT_EQ(add(0, 5), 5);
    EXPECT_EQ(add(10, 20), 30);
}

TEST(AddFunction, NegativeNumbers) {
    EXPECT_EQ(add(-2, -3), -5);
    EXPECT_EQ(add(-10, 5), -5);
    EXPECT_EQ(add(-10, -20), -30);
}

TEST(AddFunction, Zero) {
    EXPECT_EQ(add(0, 0), 0);
    EXPECT_EQ(add(0, -5), -5);
    EXPECT_EQ(add(0, 10), 10);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

