#include<iostream>
using namespace std;

int main()
{
    // taking two numbers with opposite sign
    int a = 100, b = -100;
    if ((a^b)<0)
        cout<<"Yes they are of opposite sign"<<endl;
    else
        cout<<"No they aren't of opposite sign"<<endl;
    return 0;
}