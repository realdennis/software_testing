#include "gtest/gtest.h"
#include "tri.h"
TEST(Boundary, normal){
	EXPECT_EQ(tri(1, 4, 5), "Not a triangle");
	EXPECT_EQ(tri(3, 4, 5), "Scalene");
	EXPECT_EQ(tri(1, 1, 1), "Equilateral");
	EXPECT_EQ(tri(3, 3, 5), "Isosceles");
}

TEST(Decision_Table,strong){
	EXPECT_EQ(tri(10, 4, 5), "Not a triangle");//a>b+c
	EXPECT_EQ(tri(3, 9, 5), "Not a triangle");//b>a+c
	EXPECT_EQ(tri(3, 4, 8), "Not a triangle");//c>a+b
	EXPECT_EQ(tri(100,100,100),"Equilateral");//a==b==c
	//a==b
	EXPECT_EQ(tri(100,100,1),"Isosceles");
	//b==c
	EXPECT_EQ(tri(20,30,30),"Isosceles");
	//c==a
	EXPECT_EQ(tri(2,10,2),"Not a triangle");
	//a!=b
	EXPECT_EQ(tri(4,5,3),"Scalene");
	//b!=c
	EXPECT_EQ(tri(50,100,200),"Not a triangle");
	//c!=a
	EXPECT_EQ(tri(5,5,4),"Isosceles");
}