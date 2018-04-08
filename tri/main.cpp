#include <iostream>
#include "tri.h"
using namespace std;

int main(){

    int a,b,c;

    cout << "Enter 3 integer for triangle: ";
    cin >> a >> b >> c;

    string ans;
    ans = tri(a, b, c);
    cout <<  ans << endl;
    return 0;
}
