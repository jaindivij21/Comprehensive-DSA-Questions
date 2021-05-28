// Chewbacca and number Problem
// https://www.hackerrank.com/contests/launchpad-1-winter-challenge/challenges/chewbacca-and-number

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // input the string
    string x;
    cin >> x;

    for(int i = 0; i != x.length(); i++)
    {
        // to avoid leading zeroes
        if(x[0]=='9')
            continue;
        // if the digit is more than 5, subtract it from 9
        if(x[i] >= '5')
            x[i] = '9'- x[i] + '0'; // eg. '59'(9) - '57'(7) + '50'(0) = '52'(2)
    }
    cout<<x<<endl;

    return 0;
}