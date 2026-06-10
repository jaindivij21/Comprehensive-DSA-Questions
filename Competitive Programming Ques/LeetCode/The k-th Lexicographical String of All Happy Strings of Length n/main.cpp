// Leetcode: The k-th Lexicographical String of All Happy Strings of Length n
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    void recursiveHelper(int &n, vector<string> &ans, string temp) {
        // Base Case:
        // A happy string of length n has been formed.
        if (temp.size() == n) {
            ans.push_back(temp);
            return;
        }

        // Recursive Case:
        // First character can be a, b, or c.
        if (temp.empty()) {
            recursiveHelper(n, ans, temp + 'a');
            recursiveHelper(n, ans, temp + 'b');
            recursiveHelper(n, ans, temp + 'c');
            return;
        }

        char lastChar = temp.back();

        // Recursive Case:
        // Add a character different from the last one.
        if (lastChar == 'a') {
            recursiveHelper(n, ans, temp + 'b');
            recursiveHelper(n, ans, temp + 'c');
        } else if (lastChar == 'b') {
            recursiveHelper(n, ans, temp + 'a');
            recursiveHelper(n, ans, temp + 'c');
        } else {  // lastChar == 'c'
            recursiveHelper(n, ans, temp + 'a');
            recursiveHelper(n, ans, temp + 'b');
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        recursiveHelper(n, ans, "");

        return ans.size() < k ? "" : ans[k - 1];
    }
};

int main() {
    Solution solution;
    int n, k;
    cin >> n >> k;

    cout << solution.getHappyString(n, k) << endl;

    return 0;
}