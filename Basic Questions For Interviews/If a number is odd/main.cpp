// If the number is odd

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    // for a digit to be odd, last bit must be 1
    int ans = n & 1;
    if (ans == 1)
        cout << "Odd";
    else
        cout << "Even";

    return 0;
}