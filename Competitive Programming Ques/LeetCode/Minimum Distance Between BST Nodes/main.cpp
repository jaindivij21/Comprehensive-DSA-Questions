// Leetcode : Minimum Distance Between BST Trees
// https://leetcode.com/problems/minimum-distance-between-bst-nodes/

// Do a simple inorder traversal of the tree and in the process compare every node with the previous node

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

TreeNode *buildTree(TreeNode *root) {
    int ele;
    cin >> ele;

    if (ele == -1)
        return nullptr;
    else {
        auto *temp = new TreeNode(ele);
        temp->left = buildTree(temp->left);
        temp->right = buildTree(temp->right);
        return temp;
    }
}

void inorder(const TreeNode *root, int &ans, int &pre) {
    // base case
    if (!root)
        return;
    // recursive case
    inorder(root->left, ans, pre);
    ans = min(ans, abs(root->val-pre));
    pre = root->val;
    inorder(root->right, ans, pre);
}

int minDiffInBST(TreeNode *root) {
    int ans = INT_MAX;
    int prev = INT_MIN;
    inorder(root, ans, prev);
    return ans;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    cout << minDiffInBST(root);
    return 0;
}