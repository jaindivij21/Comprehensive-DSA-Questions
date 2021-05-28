// Program to find sqare root of a number
// Using Binary Search -> in Monotonic search spaces
// O(logn + P)

#include<iostream>

using namespace std;

float squareRoot(int n, int p) {
    // using binary search to get the before decimal digits
    int s = 0;
    int e = n;
    float ans = -1;
    // normal binary search
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (mid * mid == n)
            return mid;
        else if (mid * mid < n) {
            ans = mid;
            s = mid + 1;
        } else
            e = mid - 1;
    }

    // brute force to compute the after decimal digits
    // floating part
    float inc = 0.1;

    for (int i = 0; i < p; i++) {
        while (ans * ans <= n) {
            ans += inc;
        }
        // overshot the value
        ans -= inc;
        // update the inc value;
        inc /= 10;
    }

    return ans;
}

int main() {
    cout << "Enter the number and the precision" << endl;
    int n, p;
    cin >> n >> p;

    cout << squareRoot(n, p) << endl;
    return 0;
}