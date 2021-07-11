// Leetcode : Permutation
// https://leetcode.com/problems/permutations/
// https://www.youtube.com/watch?v=mEBEw_xScsE&ab_channel=AnujBhaiya

// uses set

#include <bits/stdc++.h>

using namespace std;

// helper function
void backtrack(vector<int> &permutation, vector<int> &nums, vector<vector<int>> &ans, set<int> &included) {
    // base case
    if (permutation.size() == nums.size()) {
        ans.push_back(permutation);
        return;
    }
    // recursive case
    for (int i = 0; i < nums.size(); i++) {
        // for all the possible elements in the array
        // if the indexed element is already visited, continue onto the next index
        if (included.find(nums[i]) != included.end())
            continue;

        // fix the index i and mark it included
        permutation.push_back(nums[i]);
        included.insert(nums[i]);

        backtrack(permutation, nums, ans, included);

        // erase this fixed position
        permutation.pop_back();
        included.erase(nums[i]);
    }
}

// main function :: backtracking (recursion)
vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> ans; // main answer
    vector<int> permutation;
    // extra space array that tells if that index has been included/visited : other approach will be more time consuming but space efficient (check above video) : it involves swapping elements bw indexes
    set<int> included;
    backtrack(permutation, nums, ans, included);
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