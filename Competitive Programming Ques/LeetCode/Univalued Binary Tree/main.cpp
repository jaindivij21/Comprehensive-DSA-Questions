// Univalued Binary Tree
// Leetocode : https://leetcode.com/problems/univalued-binary-tree/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool dfs(TreeNode *root, int val) {
    // base case
    if (root == nullptr)
        return true;
    // recursive cases
    return (root->val == val) && dfs(root->left, val) && dfs(root->right, val);
}

bool isUnivalTree(TreeNode *root) {
    int val = root->val;
    return dfs(root, val);
}

int main() {


    return 0;
}