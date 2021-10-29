// Leetcode : Shuffle String
// https://leetcode.com/problems/shuffle-string/

#include <bits/stdc++.h>

using namespace std;

// cyclic sort
string restoreString(string &s, vector<int> &indices)
{
    for (int i = 0; i < s.size();)
    {
        // if at correct position, then continue
        if (i == indices[i])
            i++;
        // else use the cyclic sort swap
        else
        {
            swap(s[i], s[indices[i]]);
            swap(indices[i], indices[indices[i]]);
        }
    }
    return s;
}

int main()
{

    return 0;
}