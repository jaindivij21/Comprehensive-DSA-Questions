// Two Sum :: Leet Code
// https://leetcode.com/problems/two-sum/

// Use hash map to solve in O(n) time

#include<bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
    vector<int> ans;
    unordered_map<int, int> map;    // stores index and sum left
    for (int i = 0; i < nums.size(); i++) {
        auto itr = map.find(nums[i]);
        if (itr == map.end()) {
            // element not found, so add it into the map
            map.insert(make_pair(target - nums[i], i));
        } else {
            // if found, break and print the result
            ans.push_back(map[nums[i]]);
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int size;
    cin >> size;
    vector<int> v;
    int target;
    cin >> target;

    for (int i = 0; i < size; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    vector<int> ans = twoSum(v, target);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}