// Binary Tree Pruning :: Leetcode
// https://leetcode.com/problems/binary-tree-pruning/

// tc: O(n)

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

// traverse throughout the tree and return nullptr if the tree doesn't contain a 1 : use recursion
TreeNode *pruneTree(TreeNode *root) {
    // base case
    if (root == nullptr)
        return nullptr;
    // recursive cases
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    // We only trim if the node's value is 0 and it doesn't have kids
    if (root->val != 1 && root->left == nullptr && root->right == nullptr)
        return nullptr;
    else
    // Otherwise we leave the node the way it is
        return root;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    pruneTree(root);

    return 0;
}