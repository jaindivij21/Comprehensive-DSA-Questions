// https://www.codechef.com/START4C/problems/QUIZPLAG/

#include<bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >>m>>k;
        vector<int> arr;
        for (int i = 0; i < k; i++) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        // soln
        map<int, int> map;
        for (int i = 0; i < k; i++) {
            if (map.find(arr[i]) == map.end()) {
                // not found
                map.insert(make_pair(arr[i], 1));
            } else {
                map[arr[i]]++;
            }
        }

        vector<int> final;
        for (auto i: map) {
            if (i.first <= n && i.second > 1) {
                final.push_back(i.first);
            }
        }

        cout << final.size() << " ";
        for (auto i : final)
            cout << i << " ";

        cout << endl;


    }
    return 0;
}