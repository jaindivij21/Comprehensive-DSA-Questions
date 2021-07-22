// Leetcode :: Lowest Common Ancestor of Deepest Leaves
// https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

// Time Complexity: 2*O(n) -> Once for calculating the height and then to calculate lca.

#include<bits/stdc++.h>

using namespace std;

// definition of a node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// building the tree : using BFS
TreeNode *buildTree(TreeNode *&root) {
    queue<TreeNode *> q;
    int element;
    cin >> element;
    q.push(root);
    while (!q.empty()) {
        TreeNode *front = q.front();
        q.pop();
        int left, right;
        cin >> left >> right;
        if (left != -1) {
            front->left = new TreeNode(left);
            q.push(front->left);
        }
        if (right != -1) {
            front->right = new TreeNode(right);
            q.push(front->right);
        }
    }
    return root;
}

// print the tree : using BFS
void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();
            cout << front->val << " ";
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        cout << endl;
    }
}

// helper function that stores pair -> that stores the lowest ancestor and height of the tree
TreeNode *helper(TreeNode *&root, int &maxHeight, int height) {
    // base case
    if (root == nullptr)
        return nullptr;
    // recursive cases :: Postorder - both the subtrees
    TreeNode *left = helper(root->left, maxHeight, height + 1);
    TreeNode *right = helper(root->right, maxHeight, height + 1);
    TreeNode *ifFound = nullptr;
    if (height == maxHeight) {
        ifFound = root;
    }
    // return cases
    if (ifFound != nullptr)
        return ifFound;
    if (left != nullptr && right != nullptr) {
        return root;
    }
    if (left != nullptr) {
        return left;
    }
    if (right != nullptr) {
        return right;
    }
    return nullptr;
}

// cal the max height of the binary tree
int height(TreeNode *root) {
    // base case
    if (root == nullptr)
        return 0;
    // recursive cases
    int left = height(root->left);
    int right = height(root->right);
    return 1 + max(left, right);
}

TreeNode *lcaDeepestLeaves(TreeNode *root) {
    int maxHeight = height(root);
    return helper(root, maxHeight, 1);
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    printTree(root);
    cout << lcaDeepestLeaves(root)->val;
    return 0;
}