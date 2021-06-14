// Jump Game :: Leetcode
// https://leetcode.com/problems/jump-game/

// greedy :: working our way from back to the front
// intuitive -> linear approach

#include<bits/stdc++.h>

using namespace std;

bool canJump(vector<int> &nums) {
    int lastIndexDest = nums.size() - 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (i + nums[i] >= lastIndexDest) {
            lastIndexDest = i;
        }
    }
    return lastIndexDest == 0;
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

    bool ans = canJump(v);
    ans ? cout << "true" : cout << "false";

    return 0;
}