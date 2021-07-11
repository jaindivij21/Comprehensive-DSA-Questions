// Leetcode : Permutation :: Backtracking
// https://leetcode.com/problems/permutations/
// https://www.youtube.com/watch?v=mEBEw_xScsE&ab_channel=AnujBhaiya

// using swapping to fix elements
// O(n*n!)
#include <bits/stdc++.h>

using namespace std;

// helper function :: pass nums array by value and not reference (otherwise need to swap again during backtracking)
void backtrack(vector<int> &nums, int i, vector<vector<int>> &ans) {
    // base case
    if (i == nums.size()) {
        // if the size of nums array is eql to the i, means we have a permutation, so add the nums array to the ans vector
        ans.push_back(nums);
    }
    // recursive cases 
    else {
        // fix one element from the nums array one by one
        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            backtrack(nums, i + 1, ans);
            swap(nums[i], nums[j]); // backtrack swap
        }
    }
}

// main function :: backtracking (recursion)
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans;
    // backtrack helper function
    backtrack(nums, 0, ans);
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

    vector<vector<int>> ans = permute(arr);

    return 0;
}