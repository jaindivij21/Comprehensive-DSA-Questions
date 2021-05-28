// Program to swap n bits bw two differnt locations

// IMPORTANT
// Concept of BitMasks 
// 1U = (unsigned value 1)
// 1U << 0 = 1 binary: 00000000000000000000000000000001
// 1U << 1 = 2 binary: 00000000000000000000000000000010
// 1U << 2 = 4
// etc...

#include<iostream>
#include <cmath>
using namespace std;

int swapBits(unsigned int x, unsigned int p1, unsigned int p2, unsigned int n)  
{  
    int result;
    // here you can use the bitmasks like this or using exponents
    // int set1 = (x >> p1) & ((1U << n) - 1); 
    // int set2 = (x >> p2) & ((1U << n) - 1);  
    // remember pow has more time complexity
    
    // example number = 1 110 1 101 and bits = 3

    // extracted set1 and set2
    int temp = (pow(2.0,n)-1);
    int set1 = (x >> p1) & temp;    // 110
    int set2 = (x >> p2) & temp;    // 101
    // 
    int xo = set1 ^ set2;   // 011
    xo = (xo<<p1) | (xo<<p2);   // 0 011 0 011

    result = xo ^ x;
    return result;  
}  

int main()
{   
    int number, p1, p2, bits;
    cout<<"Enter the number, position 1, position 2 and the number of bits to be shifted (Position starting from 0 from the right)"<<endl;
    cin>>number>>p1>>p2>>bits;
    if (p1+bits > p2)
    {
        cout<<"The positions overlap, kindly reconsider"<<endl;
        cout<<"Enter the number, position 1, position 2 and the number of bits to be shifted (Position starting from 0 from the right)"<<endl;
        cin>>number>>p1>>p2>>bits;
    }
    int res = swapBits(number, p1, p2, bits);  
    cout << "Result = " << res;  
    return 0;
}