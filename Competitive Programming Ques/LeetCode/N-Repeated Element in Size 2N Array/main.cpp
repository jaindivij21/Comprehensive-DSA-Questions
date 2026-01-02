// Leetcode: N-Repeated Element in Size 2N Array
// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> uniqNums;

        for (auto i : nums) {
            if (uniqNums.find(i) != uniqNums.end()) return i;
            uniqNums.insert(i);
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 3};

    cout << sol.repeatedNTimes(nums) << endl;

    return 0;
}