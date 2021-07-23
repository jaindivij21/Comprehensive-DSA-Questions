// Uses Bitmasking

#include<bits/stdc++.h>

using namespace std;

// definition of a node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution2 {
        int count = 0;

        public int pseudoPalindromicPaths(TreeNode *root) {
            dfs(root, 0);
            return count;
        }

        private void dfs(TreeNode root, int path) {
            if (root == null)
                return;
            path = path ^ (1 << root.val);
            if (root.left == null && root.right == null) {
                // count += Integer.bitCount(path) <= 1 ? 1 : 0;
                count += (path & (path - 1)) == 0 ? 1 : 0; // check if number of set bit is <= 1
                return;
            }
            dfs(root.left, path);
            dfs(root.right, path);
        }
    }