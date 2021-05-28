// Program to Interchange two numbers without using temporary variabled

#include<iostream>
using namespace std;

int main()
{   
    int a, b;
    cout<<"Input both the numbers"<<endl;
    cin>>a>>b;

    cout<<"The numbers are a:"<<a<<" b:"<<b<<endl;

    //Swapping using the XOR Bitwise Operator
    a = a^b;
    b = a^b;
    a = a^b;

    cout<<"The interchanged numbers are a:"<<a<<" b:"<<b<<endl;
    
    return 0;
}