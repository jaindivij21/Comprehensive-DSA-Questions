// Pleasant Pairs
// https://www.youtube.com/watch?v=vHavxvnCxik

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        long long int a[n + 1];
        // input array
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        // main part
        int ans = 0;
        // for every i
        for (int i = 1; i <= n; i++) {
            // we check subsequent j's but we skip many pairs in the process thus bringing time complexity to O(NlogN)
            for (int j = a[i] - i; j <= n; j += a[i]) {
                if (j >= 0) {
                    // check conditions
                    if (a[i] * a[j] == i + j && i < j)
                        ans++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}