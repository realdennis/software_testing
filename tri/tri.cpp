#include<iostream>
#include<string>
using namespace std;

int isATriangle(int a, int b,int c){
	if(	a<(b+c)	&&	b<(a+c)	&&	c<(a+b)	) return 1;	
	return 0;
}

string typeOfTriangle(int a,int b, int c){
	//能進到這個function表示確定是三角形
	//case 1 Scalene
	if(a!=b && b!=c && c!=a) return "Scalene"; //三邊不相等
	else if(a==b && b==c) return "Equilateral";
	return "Isosceles";
}

string tri(int a,int b, int c)
{
	if(isATriangle(a,b,c)){
		return typeOfTriangle(a,b,c);
	}
	else return "Not a triangle";
}