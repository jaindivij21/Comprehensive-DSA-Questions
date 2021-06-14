// Remove duplicates from sorted array :: Leetcode
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include<bits/stdc++.h>

using namespace std;

// 2 pointer approach
int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
        // empty array
        return 0;
    }

    // using two pointers run a loop in  O(n) time.
    int i = 0;
    int j = 0;  // indexes

    // until the j reaches end of the array
    while (j < nums.size()) {
        // store the current element at j and replace it with that at ith index
        int currElement = nums[j];
        nums[i++] = currElement;
        while (j<nums.size() && nums[j] == currElement)
            j++;    // until we get the same element, just skip! but make sure you're not going out of bounds
    }
    return i;
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

    int len = removeDuplicates(v);
    for (int i = 0; i < len; i++) {
        cout << v[i] << " ";
    }

    return 0;
}