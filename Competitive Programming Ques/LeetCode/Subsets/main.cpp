// Subsets : Leetcode
// https://leetcode.com/problems/subsets/

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

// Using bitmasking
vector<vector<int>> subsets(vector<int> &nums) {
    // since max len of array is 10
    int bitmasks = (int) pow(2, nums.size()) - 1;

    vector<vector<int>> ans;
    for (int i = 0; i <= bitmasks; i++) {
        vector<int> subset;
        int num = i;    // our bitmask
        int j = nums.size() - 1;
        while (num > 0) {
            int lastBit = num & 1;  // extract last bit
            num = num >> 1;   // right shift by 1 to process the remaining bitmask during next iteration
            if (lastBit == 1 && j >= 0) {
                // that number should be included in the array
                subset.push_back(nums[j]);
            }
            j--;
        }
        ans.push_back(subset);
    }
    return ans;
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

    vector<vector<int>> ans = subsets(v);

    for (auto i: ans) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}