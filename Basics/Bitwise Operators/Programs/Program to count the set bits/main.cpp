// Program to count the set bits in a number using bitwise operators

#include<iostream>

using namespace std;

int countSetBits(int num) {
    int ans = 0;
    while (num > 0) {
        num = num & (num - 1);  // when you & a number with num - 1, we get a result with a set bit removed from right to left 
        ans++;
    }
    return ans;
}


int main() {
    // Enter the number
    cout << "Enter the number" << endl;
    int num;
    cin >> num;

    // inbuilt function
    cout << __builtin_popcount(num) << endl;

    // basic method can be using a while loop until num is greater than 0 and checking if last bit is set or not
    // and then right shifting the num by 1 & doing the comparison all over again. TC = O(logn)

    // but there is a faster method with time complexity of = O(number of set bits in the number)
    cout << countSetBits(num) << endl;

    return 0;
}