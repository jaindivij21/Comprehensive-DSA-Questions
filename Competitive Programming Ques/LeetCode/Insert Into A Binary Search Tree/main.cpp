// Insert into a binary search tree :: Leetcode
// https://leetcode.com/problems/insert-into-a-binary-search-tree/

// O(logn) time since its a BST

#include<bits/stdc++.h>

using namespace std;

// class of node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

// build Tree : bfs (level-order)
TreeNode *buildTree(TreeNode *root) {
    queue<TreeNode *> q;
    int element;
    cin >> element;
    root = new TreeNode(element);
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

// print Tree : bfs (level order)
void printTree(TreeNode *&root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        for (int i = 0; i < q.size(); i++) {
            TreeNode *front = q.front();
            q.pop();
            cout << front->val << " ";
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        cout << endl;
    }
}

// helper function that adds it to the leaf
void helper(TreeNode *&root, int val) {
    // pass the root by reference because we will be adding the node
    // base case : if we reach the leaf node, add the new value node to the tree 
    if (root == nullptr) {
        root = new TreeNode(val);
        return;
    }
    // recursive cases : move to the left sub tree or right sub tree as per the need
    if (root->val > val)
        helper(root->left, val);
    if (root->val < val)
        helper(root->right, val);
}

// a node needs to be added to a BST Tree : any node can be added to an appropriate leaf without having to change the remaining tree
TreeNode *insertIntoBST(TreeNode *&root, int val) {
    if (root == nullptr)
        return new TreeNode(val);
    else {
        helper(root, val);
        return root;
    }
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    int val;
    cin >> val;

    TreeNode *ans = insertIntoBST(root, val);
    printTree(ans);

    return 0;
}