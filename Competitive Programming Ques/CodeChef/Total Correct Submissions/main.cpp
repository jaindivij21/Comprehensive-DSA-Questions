// https://www.codechef.com/START5B/problems/TOTCRT
// CODECHEF JUNE 2021 STARTERS
// Total Correct Submissions

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        n = 3 * n;
        map<string, int> map;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            int sol;
            cin >> sol;
            if (map.find(s) == map.end()) {
                map.insert(make_pair(s, sol));
            } else {
                map[s] += sol;
            }
        }
        vector<int> ans;
        for (auto i: map)
            ans.push_back(i.second);
        sort(ans.begin(), ans.end());
        for (auto i:ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}