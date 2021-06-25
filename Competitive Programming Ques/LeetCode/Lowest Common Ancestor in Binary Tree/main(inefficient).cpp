// Lowest Common Ancestor Of A Binary Search Tree :: Leetcode
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

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

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // base case
    if (root == nullptr)
        return root;

    // recursive cases
    TreeNode *ifFound = nullptr;
    if (root->val == p->val || root->val == q->val)
        ifFound = root;
    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    TreeNode *r = lowestCommonAncestor(root->right, p, q);

    // cases
    if (ifFound != nullptr && (l != nullptr || r != nullptr) || ifFound != nullptr && (l== nullptr && r == nullptr))
        return ifFound;
    if (ifFound == nullptr && l != nullptr && r != nullptr)
        return root;
    if (l != nullptr && r == nullptr)
        return l;
    if (l == nullptr && r != nullptr)
        return r;
    return nullptr;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);
    auto *p = new TreeNode(), *q = new TreeNode();
    cin >> p->val >> q->val;

    TreeNode *ans = lowestCommonAncestor(root, p, q);
    cout << ans->val;

    return 0;
}
