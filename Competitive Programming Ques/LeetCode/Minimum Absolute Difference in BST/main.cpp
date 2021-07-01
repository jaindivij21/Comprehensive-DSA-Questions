#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorder(TreeNode *root, int &ans, int &prev)
    {
        // base case
        if (root == nullptr)
            return;
        // recursive case
        inorder(root->left, ans, prev);
        ans = min(ans, abs(prev - (root->val)));
        prev = root->val;
        inorder(root->right, ans, prev);
    }

    // since its a BST, use the inorder traversal to get the min difference bw any 2 adjacent nodes
    // recursive
    int getMinimumDifference(TreeNode *root)
    {
        int ans = INT_MAX;
        int prev = INT_MAX;
        inorder(root, ans, prev);
        return ans;
    }
};