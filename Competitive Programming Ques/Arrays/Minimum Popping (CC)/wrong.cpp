// https://www.codechef.com/START4C/problems/DEQUEUE
// Fails test cases like: 1 1 3 1 1 1 2 2

#include<bits/stdc++.h>

using namespace std;

long int popping(long int n, long int m, vector<long int> &q) {
    long int ans = 0;
    long int count = 0;
    long int i = 0;
    long int j = q.size() - 1;
    vector<long int> map(n + 1);
    fill(map.begin(), map.end(), 0);

    // pop the first element
    ans++;
    count++;
    map[q[j]]++;
    j--;
    // for subsequent pops
    while (i <= j) {
        if (count == n) {
            break;
        }
        if (map[q[i]] == map[q[j]]) {
            // can do anything, lets say we pop from front
            ans++;
            if (map[q[j]] == 0)
                count++;
            map[q[j]]++;
            j--;
        } else if (map[q[i]] > map[q[j]]) {
            ans++;
            if (map[q[j]] == 0)
                count++;
            map[q[j]]++;
            j--;
        } else {
            ans++;
            if (map[q[i]] == 0)
                count++;
            map[q[i]]++;
            i++;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        long int n, m;
        cin >> n >> m;


        vector<long int> q;
        for (long int i = 0; i < m; i++) {
            long int x;
            cin >> x;
            q.push_back(x);
        }
        if (n == m) {
            cout << n << endl;
        } else if (n == 1) {
            cout << 1 << endl;
        } else {
            long int ans = popping(n, m, q);
            cout << ans << endl;
        }
    }
    return 0;
}