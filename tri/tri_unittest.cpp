#include "gtest/gtest.h"
#include "tri.h"
TEST(Boundary, normal){
	EXPECT_EQ(tri(1, 4, 5), "Not a triangle");
	EXPECT_EQ(tri(3, 4, 5), "Scalene");
	EXPECT_EQ(tri(1, 1, 1), "Equilateral");
	EXPECT_EQ(tri(3, 3, 5), "Isosceles");
}

TEST(Decision_Table,strong){
	//a>b+c
	EXPECT_EQ(tri(10, 4, 5), "Not a triangle");
	//b>a+c
	EXPECT_EQ(tri(3, 9, 5), "Not a triangle");
	//c>a+b
	EXPECT_EQ(tri(3, 4, 8), "Not a triangle");
}