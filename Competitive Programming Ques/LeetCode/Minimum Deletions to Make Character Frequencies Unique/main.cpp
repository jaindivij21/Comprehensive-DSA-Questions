// Leetcode : Minimum Deletions to make character frequencies unique
// https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// Easy Soln: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/discuss/927654/C%2B%2BJavaPython3-Simple-time-O(n)-space-O(1)-a-small-array-is-all-you-need

#include <bits/stdc++.h>

using namespace std;

// main function
int minDeletions(string &s)
{
    int ans = 0;
    unordered_map<char, int> hashFx;
    for (auto i : s)
    {
        if (hashFx.find(i) == hashFx.end())
        {
            hashFx.insert(make_pair(i, 1));
        }
        else
        {
            hashFx[i]++;
        }
    }
    set<int> set;
    auto i = hashFx.begin();
    while (i != hashFx.end())
    {
        if (set.find(i->second) != set.end() && i->second != 0)
        {
            ans++;
            i->second--;
            continue;
        }
        set.insert(i->second);
        i++;
    }
    return ans;
}

// 1
// abbbbe 1 3 0

int main()
{
    string str;
    cin >> str;

    cout << minDeletions(str);

    return 0;
}