// Maximum Depth of Binary Tree :: Leetcode
// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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

// This function calculates nothing but the maximum height of the tree :: recursive
int maxDepth(TreeNode *root) {
    // base case
    if (root == nullptr)
        return 0;

    // recursive cases
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return max(lh, rh) + 1;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);

    // result
    cout << maxDepth(root);

    return 0;
}
