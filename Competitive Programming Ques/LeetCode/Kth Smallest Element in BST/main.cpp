// Leetcode : Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// Main idea is to do an inorder traversal of the BST so as to get the numbers in ascending order and then return the kth element.
// Time Complexity : Complete Traversal of Tree i.e. O(n)

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

// pre-order tree building
TreeNode *buildTree(TreeNode *&root) {
    int ele;
    cin >> ele;
    if (ele == -1) {
        return nullptr;
    }
    auto *temp = new TreeNode(ele);
    temp->left = buildTree(root->left);
    temp->right = buildTree(root->right);
}

// helper traversal function
void helper(TreeNode *root, vector<int> &ans) {
    // base case
    if (root == nullptr)
        return;
    // recursive
    helper(root->left, ans);
    ans.push_back(root->val);
    helper(root->right, ans);
}

// basic inorder traversal of the BST
int kthSmallest(TreeNode *root, int k) {
    int curr = 0;
    vector<int> ans;
    helper(root, ans);
    return ans[k-1];
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    int k;
    cin >> k;
    kthSmallest(root, k);
    return 0;
}