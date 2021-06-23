// Sym,metric Tree :: Leetcode
// https://leetcode.com/problems/symmetric-tree/

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

// helper function for isSymmetric
bool helper(TreeNode *l, TreeNode *r) {
    // base cases
    if (l == nullptr && r == nullptr)
        return true;
    if (l == nullptr || r == nullptr)
        return false;

    if (l->val != r->val)
        return false;
    else {
        // recursive case :: check if bottom trees also return true
        return helper(l->left, r->right) && helper(l->right, r->left);
    }
}

// function to check symmetry of a tree :: Recursion
bool isSymmetric(TreeNode *root) {
    return helper(root->left, root->right);
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);

    // result
    cout << isSymmetric(root);

    return 0;
}
