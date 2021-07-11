// recursive function for palindromes :: time taking and thuus gives time limit exceeded 

#include<bits/stdc++.h>

using namespace std;

// recursive helper function
bool helper(string s, int l, int r) {
    // base case
    if (l >= r)
        return true;
    // skip all the non alpha numerics
    while (!(isalnum(s[l])) && l <= r)
        l++;
    while (!(isalnum(s[r])) && l <= r)
        r--;
    if (isalnum(s[l]) && isalnum(s[r]) && tolower(s[l]) != tolower(s[r]))
        return false;

    // recursive case
    return helper(s, l + 1, r - 1);
}

// main function
bool isPalindrome(string s) {
    return helper(s, 0, s.size() - 1);
}

// main function
int main() {
    string str;
    getline(cin, str);
    cout << isPalindrome(str);

    return 0;
}