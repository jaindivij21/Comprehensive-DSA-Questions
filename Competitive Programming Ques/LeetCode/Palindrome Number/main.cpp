// Palindrome Number :: Leetcode
// https://leetcode.com/problems/palindrome-number/

#include<bits/stdc++.h>

using namespace std;

long long int reverse(int x) {
    long long int num = 0;
    while (x > 0) {
        num = num * 10 + x % 10;
        x = x / 10;
    }
    return num;
}

bool isPalindrome(int x) {
    if (x < 0)
        return false;
    if (x >= 0 && x <= 9)
        return true;
    long long rev = reverse(x);

    if (rev == x)
        return true;
    else
        return false;
}

int main() {
    int num;
    cin >> num;

    bool ans = isPalindrome(num);
    if (ans)
        cout << "true";
    else
        cout << "false";

    return 0;
}