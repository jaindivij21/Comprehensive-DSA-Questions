// Pretty Permutations
 
#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cats;
        // make the base array
        for (int i = 1; i <= n; i++) {
            cats.push_back(i);
        }
        // new cat positions
        if (n % 2 == 0) {
            // even
            for (int i = 1; i < n; i=i+2) {
                swap(cats[i], cats[i - 1]);
            }
        } else {
            // odd
            for (int i = 1; i < n - 2; i=i+2) {
                swap(cats[i], cats[i - 1]);
            }
            int a = cats[n - 3];
            int b = cats[n - 2];
            int c = cats[n - 1];
            cats[n - 3] = b;
            cats[n - 2] = c;
            cats[n - 1] = a;
        }
        for (auto i:cats)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}