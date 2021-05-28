// Playing with bits

#include<iostream>

using namespace std;

int noOfSetBits(int a, int b) {
    int ans = 0;
    // for all the numbers
    for (int i = a; i <= b; i++) {
        int t = i;
        // for each number, count all the set bits
        while (t > 0) {
            t = t & (t-1);
            ans++;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << noOfSetBits(a, b) << endl;
    }
}