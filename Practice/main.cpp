// Leetcode: Check If Digits Are Equal in String After Operations I
// https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i

#include <iostream>
using namespace std;

class Solution {
   public:
    // Recursion
    bool hasSameDigits(string s) {
        // Base Case
        if (s.size() == 2 && s[0] == s[1]) {
            return true;
        } else if (s.size() == 2) {
            return false;
        };

        // Recursive Cases
        string modifiedStr = "";
        for (int i = 0; i < s.size() - 1; i++) {
            int newNum = (s[i] - '0' + s[i + 1] - '0') % 10;
            modifiedStr.append(to_string(newNum));
        }

        return hasSameDigits(modifiedStr);
    }
};

int main() {
    Solution sol;
    string str;
    cin >> str;
    cout << sol.hasSameDigits(str);

    return 0;
}