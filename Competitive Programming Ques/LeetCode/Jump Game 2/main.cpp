// Jump Game 2
// https://leetcode.com/problems/jump-game-ii/

#include<bits/stdc++.h>

#define MAX (INT_MAX - 1000)
using namespace std;


// MEMORIZATION
vector<int> dp;

// recursive function
int recurs(vector<int> &nums, int i) {
    // base case
    if (i >= nums.size())
        return MAX;
    // if we reach the last place
    if (i == nums.size() - 1)
        return 0;
    // memorization
    if (dp[i] != -1)
        return dp[i];

    // recursive cases
    int least = MAX;
    for (int k = 1; k <= nums[i]; k++) {
        // for each index check using recusion
        least = min(least, 1 + recurs(nums, k + i));
    }
    return dp[i] = least;
}

// main function
int jump(vector<int> &nums) {
    dp.resize(10001, -1);
    return recurs(nums, 0);
}

int main() {
    int size;
    cin >> size;
    vector<int> v;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int result = jump(v);
    cout << result << endl;
    return 0;
}