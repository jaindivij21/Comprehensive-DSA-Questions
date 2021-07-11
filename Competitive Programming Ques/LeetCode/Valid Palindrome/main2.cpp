// Leetcode : Valid Palindrome
// Using 2 pointer approach

#include<bits/stdc++.h>

using namespace std;

bool helper(string s, int l, int r) {
    while (l <= r) {
        while (!isalnum(s[l]) && l <= r)
            l++;
        while (!isalnum(s[r]) && l <= r)
            r--;
        if (tolower(s[l]) != tolower(s[r]) && isalnum(s[l]) && isalnum(s[r]))
            return false;
        l++;
        r--;
    }
    return true;
}

// main function
bool isPalindrome(string s) {
    return helper(s, 0, s.size() - 1);
}

int main() {
    string str;
    getline(cin, str);
    cout << isPalindrome(str);

    return 0;
}