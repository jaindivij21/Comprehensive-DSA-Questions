// Sum of left leaves :: Leetcode
// https://leetcode.com/problems/sum-of-left-leaves/

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

void helper(TreeNode *root, int &sum, int flag) {
    // base case
    if (root == nullptr)
        return;

    // recursive cases
    if (root->left == nullptr && root->right == nullptr && flag == 1) {
        // leaf node we need i.e. left leaf node (indicated by flag being eql to 1)
        sum += root->val;
    }
    // recursive calls on left and right subtrees (with flags)
    helper(root->left, sum, 1);
    helper(root->right, sum, 0);
}

int sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    // helper function called with a flag of -1: indicating it's the root element
    helper(root, sum, -1);
    return sum;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);

    cout << sumOfLeftLeaves(root);

    return 0;
}
