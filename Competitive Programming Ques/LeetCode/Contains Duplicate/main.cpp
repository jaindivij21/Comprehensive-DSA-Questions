// Leetcode : Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/

#include <bits/stdc++.h>
using namespace std;

// we know the O(n2) method, but some other efficient methods can be  using a hash/set
bool containsDuplicate(vector<int> &nums)
{
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); i++)
    {
        if (set.find(nums[i]) != set.end())
        {
            // means the element is present
            return true;
        }
        set.insert(nums[i]);
    }
    return false;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1};
    containsDuplicate(arr);
    return 0;
}