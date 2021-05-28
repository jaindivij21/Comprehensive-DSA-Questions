// Program to swap two numbers

#include<iostream>
using namespace std;

int main()
{
    cout<<"Enter the numbers?"<<endl;
    int a,b;
    cin>>a>>b;

    // BEFORE swapping
    cout<<"a: "<<a<<" b: "<<b<<endl;

    if (a != b)
    {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    // AFTER swapping
    cout<<"a: "<<a<<" b: "<<b<<endl;

    return 0;
}