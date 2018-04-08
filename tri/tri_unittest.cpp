#include "gtest/gtest.h"
#include "tri.h"
TEST(Boundary, normal){

	EXPECT_EQ(tri(1, 4, 5), "Not a triangle");
	EXPECT_EQ(tri(3, 4, 5), "Scalene");
	EXPECT_EQ(tri(1, 1, 1), "Equilateral");
	EXPECT_EQ(tri(3, 3, 5), "Isosceles");
}
