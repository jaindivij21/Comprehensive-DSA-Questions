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

class Solution {
public:
    // solve using recursion
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // if both p and q are smaller, search in left subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        // if both p and q are bigger than root, search in right subtree
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        // if one is on left, other on right; means we are on the ancestor
        return root;    // so if none of the above conditions not hold true then this will hit.
    }
};