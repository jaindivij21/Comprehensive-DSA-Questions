// Minimum Depth of Binary Tree :: Leetcode
// https://leetcode.com/problems/minimum-depth-of-binary-tree/

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

// cal the min depth that exists in the tree
int minDepth(TreeNode *root) {
    // base case :: if one or both the child are null
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return 1;
    if (root->left == nullptr && root->right != nullptr)
        return min(INT_MAX, 1 + minDepth(root->right));
    if (root->left != nullptr && root->right == nullptr)
        return min(INT_MAX, 1 + minDepth(root->left));

    // if none are null
    // recursive cases
    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    return min(lh, rh) + 1;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);

    cout << minDepth(root);

    return 0;
}
