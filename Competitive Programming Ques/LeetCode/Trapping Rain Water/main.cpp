// Trapping Rain Water :: Leetcode
// https://leetcode.com/problems/trapping-rain-water/

#include<bits/stdc++.h>

using namespace std;

// 2 array approach (will contain the max left and max right)
int trap(vector<int> &height) {
    if (height.empty() || height.size() == 1)
        return 0;

    vector<int> left;
    vector<int> right;
    int lmax = INT_MIN;
    int rmax = INT_MIN;

    for (int i = 0; i < height.size(); i++) {
        left.push_back(lmax);
        lmax = max(lmax, height[i]);
    }
    for (int i = height.size() - 1; i >= 0; i--) {
        right.push_back(rmax);
        rmax = max(rmax, height[i]);
    }
    reverse(right.begin(), right.end());

    int count = 0;
    for (int i = 1; i < height.size() - 1; i++) {
        int temp = (min(left[i], right[i]) - height[i]);
        if (temp >= 0)
            count += temp;
    }
    return count;
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
    int ans = trap(v);
    cout << ans;

    return 0;
}
