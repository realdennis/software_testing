#include<iostream>
#include<string>
using namespace std;

int isATriangle(int a, int b,int c){
	if(	a<(b+c)	&&	b<(a+c)	&&	c<(a+b)	) return 1;	
	return 0;
}

string tri(int a,int b, int c)
{
	if(isATriangle(a,b,c)){
		return "Is A triangle";
	}
	else return "Not a triangle";
}