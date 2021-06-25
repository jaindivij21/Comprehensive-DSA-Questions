// Lowest Common Ancestor Of A Binary Tree :: Leetcode
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

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

// function that finds recursively the lowest commmon ancestor
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    // base case
    if (root == nullptr)
        return root;    // if root is null, return null

    // recursive cases :: we follow DFS : preorder (kinda) :: working in BOTTOM UP MANNER
    TreeNode *ifFound = nullptr;
    if (root->val == p->val || root->val == q->val)
        ifFound = root; // make if found eql to root if root is one of the values

    // make a recursive search in left and right subtree
    TreeNode *l = lowestCommonAncestor(root->left, p, q);
    TreeNode *r = lowestCommonAncestor(root->right, p, q);

    // cases
    // 1) if root itself is one of the target -> return it
    if (ifFound != nullptr)
        return ifFound;
    // 2) if root isn't target but both left and right trees return the targets, return the root again
    if (l != nullptr && r != nullptr)
        return root;
    // else if just one returns return that
    if (l)
        return l;
    if (r)
        return r;
    // else -> return NULL (base case)
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
