// Balanced Binary Tree :: Leetcode
// https://leetcode.com/problems/balanced-binary-tree/

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

// recursive helper function
pair<int, bool> helper(TreeNode *root) {
    // base case :: if the root is null, it's height is 0 and its balanced
    if (root == nullptr)
        return make_pair(0, true);

    // recursive case :: recursively call the function for left subtree's pair and right subtree's pair
    pair<int, bool> leftTree = helper(root->left);
    pair<int, bool> rightTree = helper(root->right);
    // cal ans -> if false is returned from below subtrees, return false other wise check the condition of balance for that node using heights
    bool ans = (max(leftTree.first, rightTree.first) - min(leftTree.first, rightTree.first) <= 1) && leftTree.second &&
               rightTree.second;

    // return the pair with height and ans's boolean
    return make_pair((max(leftTree.first, rightTree.first) + 1), ans);
}

// the solution is straightforward as we at each node need to calculate the left subtree and right sub tree height and check the difference
bool isBalanced(TreeNode *root) {
    // helper function that is recursive and returns pair (height and boolean when the tree is balanced or not)
    return helper(root).second;
}

int main() {
    TreeNode *root = nullptr;

    // build tree
    root = buildTree(root);
    cout << isBalanced(root);

    return 0;
}
