#include "gtest/gtest.h"
#include "tri.h"
TEST(Boundary, normal){
	EXPECT_EQ(tri(3, 4, 5), "Scalene");
	EXPECT_EQ(tri(1, 4, 5), "Not a triangle");
}

TEST(Boundary,robust){
	EXPECT_EQ(tri(0, 4, 5), "Not a triangle");
	EXPECT_EQ(tri(1, 4, 5), "Not a triangle");
	EXPECT_EQ(tri(3, 4, 5), "Scalene");
}