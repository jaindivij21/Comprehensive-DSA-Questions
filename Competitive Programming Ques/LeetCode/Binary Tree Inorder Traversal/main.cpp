// Inorder Traversal Of A binary tree :: Leetcode
// https://leetcode.com/problems/binary-tree-inorder-traversal/

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

// helper function : helps inorder traversal
void helper(TreeNode *root, vector<int> &ans) {
    // base case
    if (!root)
        return;
    else {
        helper(root->left, ans);
        ans.push_back(root->val);
        helper(root->right, ans);
    }
}

// print tree :: inorder traversal -> Left, Root, Right :: Recursive
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ans;
    helper(root, ans);
    return ans;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);

    // print traversal
    vector<int> final = inorderTraversal(root);
    for (auto i: final)
        cout << i << " ";

    return 0;
}
