// Leetcode: Separate the Digits in an Array
// https://leetcode.com/problems/separate-the-digits-in-an-array

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    vector<int> extractNums(int& num) {
        vector<int> temp;
        int p = 10;

        while (num != 0) {
            temp.push_back(num % p);
            num /= p;
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto i : nums) {
            for (auto j : extractNums(i)) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {13, 25, 83, 77};

    vector<int> ans = solution.separateDigits(nums);
    for (auto i : ans) {
        cout << i << endl;
    }

    return 0;
}