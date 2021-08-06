// Leetcode : Binary Tree Tilt
// https://leetcode.com/problems/binary-tree-tilt/
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

int postorder(TreeNode *root, int &ans) {
    // base case
    if (root == nullptr)
        return 0;   // 0 sum
    // recursive cases : cal the sum of left and right sub-trees
    int lSum = postorder(root->left, ans);
    int rSum = postorder(root->right, ans);
    ans += abs(rSum - lSum);    // add the tilts 
    return lSum + rSum + root->val; // return the sum of this tree
}

int findTilt(TreeNode *root) {
    int ans = 0;
    postorder(root, ans);
    return ans;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    cout << findTilt(root);
    return 0;
}