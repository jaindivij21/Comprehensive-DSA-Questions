// Leetcode : Jewels and Stones
// https://leetcode.com/problems/jewels-and-stones/

#include <bits/stdc++.h>

using namespace std;

int numJewelsInStones(string &jewels, string &stones)
{
    unordered_set<char> s;
    int ans = 0;
    for (auto i : jewels)
        s.insert(i);
    for (auto i : stones)
    {
        if (s.find(i) != s.end())
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