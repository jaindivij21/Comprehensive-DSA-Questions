// First Missing Positive :: Leetcode
// https://leetcode.com/problems/first-missing-positive/

// Constant space and time

#include<bits/stdc++.h>

using namespace std;

// The basic idea is to swap the positions of the numbers in the array such that they reside on their correct indices, later we do a second iteration and find the first number
// which isn't at the correct index and it becomes our answer; keep note that we tend to ignore the -ve and greater than n numbers.
int firstMissingPositive(vector<int> &nums) {
    int len = nums.size();

    // iterate over the entire array
    for (int i = 0; i < len; i++) {
        // 0's, -ve's and numbers greater than n are left : which have no index to be placed. so swap all the numbers other than these and till the time,
        // that correct index doesn't have the correct number; cuz if it does, we might not want to ruin that.
        while (nums[i] >= 1 && nums[i] <= len && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    // iterate over all the numbers once more and check if there is any number who doesn't match with its index
    for (int i = 0; i < len; i++) {
        if (i + 1 != nums[i])
            return i + 1;
    }
    return len + 1;
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

    int ans = firstMissingPositive(v);
    cout << ans << endl;

    return 0;
}