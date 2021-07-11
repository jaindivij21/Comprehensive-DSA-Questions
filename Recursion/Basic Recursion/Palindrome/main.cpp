
// Palindrome :: Array or string (Using Recursion)

#include<bits/stdc++.h>

using namespace std;

// main function
bool isPalindrome(string s, int l, int r) {
    // base case
    if (l >= r)
        return true;
    if (s[l] != s[r])
        return false;
    // recursive cases
    return isPalindrome(s, l + 1, r - 1);
}

int main() {
    string str;
    getline(cin, str);
    cout << isPalindrome(str, 0, str.length() - 1);

    return 0;
}