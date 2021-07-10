// C. Pair Programming
// Greedy

#include<bits/stdc++.h>

using namespace std;

// main solve function
void solve() {
    // input the data
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> a1(n);
    for (int i = 0; i < n; i++) {
        cin >> a1[i];
    }
    vector<int> a2(m);
    for (int i = 0; i < m; i++) {
        cin >> a2[i];
    }

    // stores answers
    vector<int> ans;

    // greedy logic, make the same person keep on doing the work until he cannot anymore
    // total moves for each person represented by x and y respectively
    int x = 0, y = 0;
    
    // main loop that runs until both the array pointer reach their limits
    while (x < n || y < m) {
        // this is just to keep track that there were some changes made by either of the programmers, either changed line or added line
        int prevX = x;
        int prevY = y;
    
        // 2 while loops
        // make the first programmer do as much as he can until its not possible for him, then we move onto the other one
        while (x < n && (a1[x] <= k || a1[x] == 0)) {
            if (a1[x] == 0)
                k++;    // add a line of code
            ans.push_back(a1[x]);
            x++;
        }
        // make the second programmer do now as much as he can until its not possible anymore
        while (y < m && (a2[y] <= k || a2[y] == 0)) {
            if (a2[y] == 0)
                k++;    // add a line of code
            ans.push_back(a2[y]);
            y++;
        }
        
        // if no change in the code
        if (prevX == x && prevY == y) {
            // means none of the while conditions worked : deadlock
            cout << -1 << endl;
            return;
        }
    }
    
    // print the ans array
    for (auto i: ans)
        cout << i << " ";
    cout << endl;
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}