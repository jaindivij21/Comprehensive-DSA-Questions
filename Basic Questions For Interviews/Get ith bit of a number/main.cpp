// Get ith bit of a number

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int bit;
    cin >> bit;

    int ans = (n & (1 << bit)) > 0 ? 1 : 0;
    cout << ans;

    return 0;
}