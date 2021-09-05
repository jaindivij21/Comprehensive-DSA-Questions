// Leetcode:  Find Bottom Left Tree Value
// https://leetcode.com/problems/find-bottom-left-tree-value/

// Time Complexity: o(n)

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// BFS Function 
int findBottomLeftValue(TreeNode *root) {
    int ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *temp = q.front();
            q.pop();
            // store the first number of the row in ans
            if (i == 0)
                ans = temp->val;
            // add the children
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
    return ans;
}

int main() {


    return 0;
}