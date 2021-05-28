#include<iostream>

using namespace std;

int fibo(int n) {
    // assuming fibo(n-1..) is known
    if (n <= 1) {
        // base case
        return n;
    } else
    {
        // relation bw sub problem and current ans
        int ans = fibo(n - 1) + fibo(n - 2);
        return ans;
    }
}

int main() {
    // input the number
    int n;
    cin >> n;

    cout << fibo(n) << endl;

    return 0;
}