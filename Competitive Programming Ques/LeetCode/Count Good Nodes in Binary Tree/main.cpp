// Count Good Nodes in Binary Tree :: Leetcode
// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

// TC: O(n)

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

void preorder(TreeNode *root, int max, int &x) {
    // base case
    if (root == nullptr)
        return;
    // recursive case
    if (root->val >= max) {
        max = root->val;
        x++;
    }
    preorder(root->left, max, x);
    preorder(root->right, max, x);
}

// do a basic preorder traversal and keep track of the max element
int goodNodes(TreeNode *root) {
    int x = 0;
    int max = root->val;
    preorder(root, max, x);
    return x;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    cout << goodNodes(root);

    return 0;
}