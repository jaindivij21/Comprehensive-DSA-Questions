// Binary Tree Preorder Traversal :: Leetcode
// https://leetcode.com/problems/path-sum/

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

void helper(TreeNode *root, vector<int> &ans) {
    // base case
    if (root == nullptr)
        // since the root doesn't exist, there is nothing to check for
        return;

    // recursive cases
    ans.push_back(root->val);
    helper(root->left, ans);
    helper(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *root) {
    vector<int> ans;
    helper(root, ans);
    return ans;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);

    preorderTraversal(root);

    return 0;
}
