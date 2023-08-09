// Leetcode: Minimize the Maximum Difference of Pairs
// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
// https://www.youtube.com/watch?v=lf1Pxg7IrzQ&ab_channel=NeetCodeIO

#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Method to determine that if a number threshold is supplied, can there be p pairs in the nums array,
// where max of the differences of these pairs can be equal to the threshold value.
bool isValid(vector<int> &nums, int threshold, int p) {
    int i = 0, count = 0;   // Variable to keep the count of pairs found.

    // loop over the entire array
    while (i < nums.size() - 1) {
        int difference = abs(nums[i + 1] - nums[i]);

        // Check for valid pairs
        if (difference <= threshold) {
            count++;
            i += 2; // This statement is due to the fact that one index can appear only once in all the pairs.
        } else {
            i += 1;
        }

        if (p == count) {
            // p valid pairs found
            return true;
        }
    }
    return false; // p valid pairs not found.
}

// This method returns the minimum possible number that could be the result of the maximum difference among
// any set of p pairs chosen from the given 'nums' array.
// Note that the elements of these p pairs must not repeat.
int minimizeMax(vector<int> &nums, int p) {
    // Base Case
    if (p == 0)
        return 0;

    // Sort the vector so that we can be greedy with our pairs.
    // I.e. the array would become such that the difference between the neighbors will be the minimum.
    sort(nums.begin(), nums.end());

    // Binary Search
    // We are going to take the opposite approach, where instead of calculating the differences of pairs and then
    // taking the maximum we will do the opposite, i.e. we will select a number that can be a potential
    // maximum difference for p pairs.
    int size = nums.size();

    // Result variable
    int result = INT_MAX; // Since we have to find the minimum value for the maximum amongst difference of p pairs.

    int left = 0; // The left bound - the lowest element possible in this array.
    int right = nums[size - 1] - nums[0];   // The right bound - the max of any differences between pairs in the array.

    while (left <= right) {
        int mid = left + (right - left) / 2;    // calculate the mid element.

        if (isValid(nums, mid, p)) {
            // Means that for p pairs, we this value of mid can be the maximum of the differences of these p pairs.
            // so we can store it in the result
            result = mid;

            // Reduce the search space.
            right = mid - 1;
        } else {
            // We need to search for a greater number. As we couldn't find p pairs, such that the maximum of the
            // differences of p pairs was mid.
            // For eg. [1, 1, 2, 3, 7, 10], if mid was 0, and p was 2, we would not be able to find 2 pairs such that
            // the max of the difference in these pairs shall be 0 => (1-1 = 0 (1st pair), 3-2 = 1 (2nd pair)) ->
            // max(0,1) = 1 which is not equal to 0 - thus 0 doesn't work.
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int size, p;
    cin >> size;
    cin >> p;

    vector<int> nums(size);

    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }

    cout << minimizeMax(nums, p);

    return 0;
}