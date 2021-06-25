// Path Sum :: Leetcode
// https://leetcode.com/problems/path-sum/

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

bool helper(TreeNode *root, int targetSum, int count) {
    // base case
    if (root == nullptr)
        // since the root doesn't exist, there is nothing to check for
        return false;
    if (root->left == nullptr && root->right == nullptr) {
        // leaf node :: check if count is equal to target
        return (count + root->val == targetSum);
    }
    // recursive cases :: kinda like preorder depth first search
    count += root->val; // update count
    bool l = helper(root->left, targetSum, count);  // left subtree
    bool r = helper(root->right, targetSum, count); // right subtree
    // even if one subtree return true, further return true
    return l || r;
}

// The concept is simple : we need to do a depth first traversal (iterative using a stack or recursive using recursion stack)
// and when we reach the leaf node check the sum.
bool hasPathSum(TreeNode *root, int targetSum) {
    int count = 0;
    return helper(root, targetSum, count);
}

int main() {
    TreeNode *root = nullptr;

    int target;
    cin >> target;

    // build tree
    root = buildTree(root);

    cout << hasPathSum(root, target);

    return 0;
}
