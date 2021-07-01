#include <bits/stdc++.h>
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
    // preorder : similar to calculating height (depth first search - recursion)
    // pair stores ans and height
    pair<int, int> helper(TreeNode *root)
    {
        // base case
        if (root == nullptr)
            return make_pair(0, 0);
        // recursive cases
        pair<int, int> left = helper(root->left);
        pair<int, int> right = helper(root->right);
        pair<int, int> ans = make_pair(max(left.first, max(right.first, left.second + right.second)),
                                       (max(left.second, right.second) + 1));
        return ans;
    }

    // diameter of a binary tree
    int diameterOfBinaryTree(TreeNode *root)
    {
        pair<int, int> ans;
        ans = helper(root);
        return ans.first;
    }
};