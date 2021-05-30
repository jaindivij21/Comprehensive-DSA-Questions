// 3 Sum Problem :: Leetcode
// https://leetcode.com/problems/3sum/

#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &a) {
    vector<vector<int>> final;
    int size = a.size();
    if (size < 3) {
        return final;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i <= size - 3; i++) {
        if (i == 0 || (i > 0 && a[i] != a[i - 1])) {
            int m = i + 1;
            int n = size - 1;
            int element = a[i];
            while (m < n) {
                int sum = element + a[m] + a[n];
                if (sum == 0) {
                    final.push_back({a[i], a[m], a[n]});
                    while (m < n && a[m] == a[m + 1])
                        m++;
                    while (m < n && a[n] == a[n - 1])
                        n--;
                    m++;
                    n--;
                } else if (sum > 0)
                    n--;
                else
                    m++;
            }
        }
    }
    return final;
}

int main() {
    int size;
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++) {
        int m;
        cin >> m;
        arr.push_back(m);
    }

    vector<vector<int>> ans;
    ans = threeSum(arr);

    for (auto i : ans) {
        for (auto j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}