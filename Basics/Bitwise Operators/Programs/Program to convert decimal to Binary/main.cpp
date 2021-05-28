// Program to convert deicmal to binary using bitwise operators

#include<iostream>

using namespace std;

int decimalToBinary(int n) {
    int p = 1;
    int ans = 0;
    while (n > 0) {
        int temp = (n & 1); // last bit
        ans += p * temp; // add it to the ans
        p *= 10; // update the power
        n >>= 1; // right shift the number
    }
    return ans;
}

int main() {
    cout << "Enter the number" << endl;
    int n;
    cin >> n;

    int ans = decimalToBinary(n);
    cout << "The decimal Equivalent is " << ans << endl;

    return 0;
}