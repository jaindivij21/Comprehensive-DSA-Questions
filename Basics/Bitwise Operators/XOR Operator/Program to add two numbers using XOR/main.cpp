// Program to add two numbers without aritmentic operations

#include<iostream>
using namespace std;

int Add(int x, int y)  
{
    // Iterate till there is no carry  
    while (y != 0)  
    {  
        int carry = x & y;  // calculate the carry
        x = x ^ y;      // add the two numbers without the carry consideration
        y = carry << 1;  // store the carry in y after a left shift for correct placement (cuz carry left vale number ke upar lagti hai)
    }  
    return x;  
}  

int main()
{
    int a, b;
    cout<<"Enter the numbers to be added"<<endl;
    cin>>a>>b;
    int res = Add(a, b);  
    cout<<res<<endl;
    return 0;
}