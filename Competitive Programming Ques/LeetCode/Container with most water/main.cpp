// Container with most water: Leetcode
// https://leetcode.com/problems/container-with-most-water/

// 2 pointer approach

#include<bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height) {
    int res = INT_MIN;
    int l = 0;
    int r = height.size() - 1;

    while (l < r) {
        if (height[l] <= height[r]) {
            res = max(res, (r - l) * height[l]);
            l++;
        } else {
            res = max(res, (r - l) * height[r]);
            r--;
        }
    }
    return res;
}

int main() {
    int size;
    cin >> size;
    vector<int> height(size);

    for (int i = 0; i < size; i++) {
        int n;
        cin >> n;
        height.push_back(n);
    }

    int ans = maxArea(height);
    cout << ans << endl;

    return 0;
}