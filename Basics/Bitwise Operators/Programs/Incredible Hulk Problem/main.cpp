// This Problem is same as counting the set bits in a number
// Ex. 23 = 1 + 0 + 1 + 1 + 1
//          16  8   4   2   1          -------- powers of 2
// https://www.youtube.com/watch?v=A1H8L7hQ3pE

#include<iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;
        int ans = 0;
        while (num > 0) {
            num = num & (num - 1);
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}