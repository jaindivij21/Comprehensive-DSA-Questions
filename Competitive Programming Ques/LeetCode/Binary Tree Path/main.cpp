// Binary Tree Path :: Leetcode
// https://leetcode.com/problems/binary-tree-path/

// Somewhat efficient than a normal binary tree as we make use of binary tree properties

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

void helper(TreeNode *root, string s, vector<string> &ans) {
    // base case
    if (root == nullptr)
        return;
    // recursive cases
    if (root->left == nullptr && root->right == nullptr) {    // leaf node
        s.append(to_string(root->val));
        ans.push_back(s);
    } else {
        s.append(to_string(root->val) + "->");
    }
    helper(root->left, s, ans);
    helper(root->right, s, ans);
}

// apply a normal depth first traversal
vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> ans;
    string str = "";
    helper(root, str, ans);
    return ans;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);

    vector<string> ans = binaryTreePaths(root);

    return 0;
}
