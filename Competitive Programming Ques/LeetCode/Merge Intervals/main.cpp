// Merge Intervals :: Leetcode
// https://leetcode.com/problems/merge-intervals/

#include<bits/stdc++.h>

using namespace std;

bool static compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> ans;

    // sort the intervals based on their start point
    sort(intervals.begin(), intervals.end(), compare);

    // now traverse over the vector and start merging
    int j = 0;  // pointer for the ans array
    for (int i = 0; i < intervals.size(); i++) {
        if (ans.empty() || ans[j][1] < intervals[i][0]) {
            // no overlap
            ans.push_back({intervals[i][0], intervals[i][1]});
            j = ans.size() - 1;
        } else {
            // overlap
            ans[j][1] = max(ans[j][1], intervals[i][1]);
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> intervals;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        intervals.push_back({x, y});
    }

    vector<vector<int>> ans = merge(intervals);

    for (auto i: ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
