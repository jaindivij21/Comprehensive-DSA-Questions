// Invert Binary Tree :: Leetcode
// https://leetcode.com/problems/invert-binary-tree/

#include<bits/stdc++.h>

using namespace std;

// tree structure
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructors
    explicit TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int d) : val(d), left(nullptr), right(nullptr) {}

    TreeNode(int d, TreeNode *l, TreeNode *r) : val(d), left(l), right(r) {}
};

// building a tree :: preorder traversal -> Root,Left,Right :: Recursive function
TreeNode *buildTree(TreeNode *&root) {
    int element;
    cin >> element;

    // base case
    if (element == -1)
        return nullptr;
        // recursive case
    else {
        root = new TreeNode(element);
        root->left = buildTree(root->left);
        root->right = buildTree(root->right);
        return root;
    }
}

// function to invert a binary tree :: can be solved using BFS traversal and also using 'DFS'
TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
        return root;
    TreeNode *l = invertTree(root->left);
    TreeNode *r = invertTree(root->right);
    root->left = r;
    root->right = l;
    return root;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);

    invertTree(root);

    return 0;
}
