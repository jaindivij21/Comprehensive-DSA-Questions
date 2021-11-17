// Leetcode : Split a String in Balanced Strings
// https://leetcode.com/problems/split-a-string-in-balanced-strings/

#include <bits/stdc++.h>

using namespace std;

int balancedStringSplit(string &s)
{
    int l = 0, r = 0, ans = 0;
    for (auto i : s)
    {
        if (i == 'L')
            l++;
        else
            r++;
        if (l == r)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}