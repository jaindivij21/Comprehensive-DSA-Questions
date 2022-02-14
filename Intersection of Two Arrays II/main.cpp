// Intersection of Two Arrays II :: Leetcode
// https://leetcode.com/problems/intersection-of-two-arrays-ii/

#include <bits/stdc++.h>
using namespace std;

vector<int> helper(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> ans;
    // nums2 will be smaller here
    unordered_map<int, int> map;
    for (int i = 0; i < nums2.size(); i++)
    {
        if (map.find(nums2[i]) == map.end())
            map.insert(make_pair(nums2[i], 1));
        else
            map[nums2[i]]++;
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        if (map.find(nums1[i]) != map.end() && map[nums1[i]] >= 1)
        {
            ans.push_back(nums1[i]);
            map[nums1[i]]--;
        }
    }
    return ans;
}

// One way would be to sort and do a binary search - nlogn time.
// Other way is to simply use hash maps
vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    if (m >= n)
    {
        return helper(nums1, nums2);
    }
    else
    {
        return helper(nums2, nums1);
    }
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    vector<int> ans = intersect(nums1, nums2);
    return 0;
}