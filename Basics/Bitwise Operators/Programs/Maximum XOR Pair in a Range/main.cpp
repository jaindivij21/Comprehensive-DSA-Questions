// Maximizing XOR Problem
// https://www.hackerrank.com/challenges/maximizing-xor/problem
// NICE PROBLEM

#include<iostream>
using namespace std;

int maxXor(int a, int b) {
    // Logic: We can observe that after the XOR of L and R, the ans's most significant bit of this XOR will tell us the maximum
    // value we can achieve i.e. let XOR of L and R is y1xxx where y is 0 and x can be 0 or 1 then maximum XOR value we can get is 01111
    
    // msb contains the the number of bits in the XOR of a and b thus telling us no of bits from right before we get our last 1 or set bit. ex in 01011, its value is 4
    int msb = 0;
    int num = a^b;
    while (num > 0) {
        msb++;
        num >>= 1;
    }

    // msb has the maximum 1's that can be there
    // return the number formed eg. if msb is 4 == 1111 == (15) is the ans
    num = 0;
    int temp = 1;
    while(msb--)
    {
        num += temp;
        temp *= 2;
    }
    return num;
}

// main
int main() {
    int a, b;
    cin >> a >> b;
    cout << maxXor(a, b) << endl;
    return 0;
}