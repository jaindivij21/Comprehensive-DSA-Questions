// Jump Game :: Leetcode
// https://leetcode.com/problems/jump-game/

// recursive (TLE)

#include<bits/stdc++.h>

using namespace std;

bool helper(vector<int> &nums, int index) {
    // base case
    if (index == nums.size() - 1)
        return true;
    if (index >= nums.size() || (nums[index] == 0 && index < nums.size() - 1))
        return false; // out of bounds

    // recursive cases
    int i = nums[index];
    while (i != 0) {
        bool temp = helper(nums, i + index);
        if (temp) {
            return true;
        }
        i--;
    }
    return false;
}

bool canJump(vector<int> &nums) {
    bool ans = helper(nums, 0);
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    bool ans = canJump(v);
    ans ? cout << "true" : cout << "false";

    return 0;
}