// https://www.codechef.com/problems/CTIME

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n, k, f;
        cin >> n >> k >> f;

        vector<pair<int, int>> v(n);

        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            pair<int, int> temp = make_pair(x, y);
            v[i] = temp;
        }

        sort(v.begin(), v.end());

        int invTime = 0;
        int maxEnd = v[0].second;

        invTime += v[0].first;
        for (int i = 1; i < n; i++) {
            invTime += max(0, v[i].first - maxEnd);
            maxEnd = max(maxEnd, v[i].second);
        }
        invTime += f - maxEnd;

        int freeTime = invTime;
        cout << (freeTime >= k ? "YES" : "NO") << endl;
    }

    return 0;
}