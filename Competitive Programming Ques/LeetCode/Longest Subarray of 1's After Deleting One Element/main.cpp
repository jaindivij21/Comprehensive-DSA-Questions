// Leetcode: Longest Subarray of 1's After Deleting One Element
// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

#include <iostream>
#include <vector>

using namespace std;

// Method to return the Longest Subarray of 1's After Deleting One Element
int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    int maxLength = 0;
    int leftOnes = 0;
    int rightOnes = 0;

    // Iterate over the array
    // Through the iteration, whenever we encounter a 0, we calculate the 1's subarray length
    // if we remove the preceding 0.
    for (auto num: nums) {
        if (num == 1) {
            rightOnes++;
        } else {
            maxLength = max(maxLength, leftOnes + rightOnes);
            leftOnes = rightOnes;
            rightOnes = 0;
        }
    }

    // Handle the case of all 1's
    if (rightOnes == n)
        return rightOnes - 1;

    // Handle the case of all 0's
    if (maxLength == 0 && leftOnes == 0 && rightOnes == 0)
        return 0;

    // Handle the case for the last 0's removal
    return max(maxLength, leftOnes + rightOnes);
}

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);

    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    cout << "Result: " << longestSubarray(nums);

    return 0;
}
