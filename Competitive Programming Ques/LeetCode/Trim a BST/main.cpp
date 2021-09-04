// Leetcode : Trim a BST
// https://leetcode.com/problems/trim-a-binary-search-tree/

// Time Complexity:

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

// Build Tree Function : preorder traversal
TreeNode *buildTree(TreeNode *&root) {
    int element;
    cin >> element;
    // base case
    if (element == -1) {
        return nullptr;
    }
        // recursive part
    else {
        root = new TreeNode(element);
        root->left = buildTree(root->left);
        root->right = buildTree(root->right);
        return root;
    }
}

// main function
TreeNode *trimBST(TreeNode *root, int L, int R) {
    if (root == nullptr) return nullptr;
    if (root->val < L) return trimBST(root->right, L, R);
    if (root->val > R) return trimBST(root->left, L, R);
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    root = trimBST(root, 1, 3);
    return 0;
}