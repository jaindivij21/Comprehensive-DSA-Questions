// Leetcode: Leaf-Similar Trees
// https://leetcode.com/problems/leaf-similar-trees/

#include<bits/stdc++.h>

using namespace std;

// Tree Node Structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// build Tree ::  preorder
TreeNode *buildTree(TreeNode *&root) {
    int element;
    cin >> element;
    // base case
    if (element == -1)
        return nullptr;
        // recursive case
    else {
        auto *temp = new TreeNode(element);
        temp->left = buildTree(root->left);
        temp->right = buildTree(root->right);
        return temp;
    }
}

// dfs
void dfs(TreeNode *&root, vector<int> &v) {
    // base case
    if (root == nullptr)
        return;
    // recursive case
    if (root->left == nullptr && root->right == nullptr) {
        // leaf node
        v.push_back(root->val);
    }
    dfs(root->left, v);
    dfs(root->right, v);
}

// traverse over the both the roots/trees
bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    vector<int> ans1;
    vector<int> ans2;
    dfs(root1, ans1);
    dfs(root2, ans2);
    return ans1 == ans2;
}

int main() {
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;
    root1 = buildTree(root1);
    root2 = buildTree(root2);
    leafSimilar(root1, root2);
    return 0;
}