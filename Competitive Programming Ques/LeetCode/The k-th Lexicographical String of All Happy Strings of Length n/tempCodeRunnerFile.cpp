class Solution {
   public:
    void recursiveHelper(int &n, vector<string> &ans, string temp) {
        // Base Case
        if (temp.size() == n) {
            ans.push_back(temp);
        }

        // Recursive Cases
        if (temp.empty()) {
            recursiveHelper(n, ans, temp + "a");
            recursiveHelper(n, ans, temp + "b");
            recursiveHelper(n, ans, temp + "c");
        }

        char lastChar = temp[temp.size() - 1];
        if (lastChar == 'a') {
            recursiveHelper(n, ans, temp + 'b');
            recursiveHelper(n, ans, temp + "c");
        } else if (lastChar == 'b') {
            recursiveHelper(n, ans, temp + "a");
            recursiveHelper(n, ans, temp + "c");
        } else {
            recursiveHelper(n, ans, temp + "a");
            recursiveHelper(n, ans, temp + "b");
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        recursiveHelper(n, ans, "");

        return ans.size() > k ? "" : ans[k - 1];
    }
};
