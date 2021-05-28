// Optimal Binary String
// For a binary string of length N, count the ones which have no consecutive 1's.

#include<iostream>

using namespace std;

int optimalBinString(int n) {
    // base case
    if (n <= 0) {
        return 1;
    }
    if(n == 1)
    {
        return 2;
    }
    // recursive
    // fibonacci pattern
    return optimalBinString(n-1)+optimalBinString(n-2);
}

int main() {
    // input the length of binary string
    int num;
    cin >> num;

    cout << "Binary string of len " << num << " that dont contain consecutive 1's: " << optimalBinString(num) << endl;
    return 0;
}