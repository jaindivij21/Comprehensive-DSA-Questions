// Same Tree :: Leetcode
// https://leetcode.com/problems/same-tree/

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

// simple recursive function that compares values and checks if the 2 trees are similar
bool isSameTree(TreeNode *p, TreeNode *q) {
    bool ans = false;
    // base case
    if (p == nullptr && q == nullptr)
        return true;
    if (p == nullptr || q == nullptr)
        return false;

    if (p->val != q->val)
        ans = false;
    else {
        ans = true;
    }
    // recursive case
    return ans && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;

    // build tree
    root1 = buildTree(root1);
    root2 = buildTree(root2);

    // result
    cout << isSameTree(root1, root2);

    return 0;
}
