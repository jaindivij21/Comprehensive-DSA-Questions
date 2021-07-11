// Leetcode : Permutation II :: Backtracking
// https://leetcode.com/problems/permutations-ii/
// https://www.youtube.com/watch?v=mEBEw_xScsE&ab_channel=AnujBhaiya

// using swapping to fix elements
// Unique Permutations --> made possible using sets

#include <bits/stdc++.h>

using namespace std;

// helper function
void backtrack(vector<int> nums, int i, set<vector<int>> &tempans) {
    if (i == nums.size()) {
        tempans.insert(nums);
    } else {
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1, tempans);
        }
    }
}

// main function :: backtracking (recursion)
vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> ans;
    set<vector<int>> tempans;
    backtrack(nums, 0, tempans);
    for (auto i:tempans) {
        ans.push_back(i);
    }
    return ans;
}

int main() {
    // input
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> ans = permuteUnique(arr);

    return 0;
}