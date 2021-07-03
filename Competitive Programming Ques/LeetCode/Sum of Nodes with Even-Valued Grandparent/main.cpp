// Find a Corresponding Node of a Binary Tree in a Clone of That Tree :: Leetcode
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

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
void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
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

// preorder
void preorder(TreeNode *root, int &sum) {
    // base case
    if (root == nullptr)
        return;
    // recursive case
    if (root->val % 2 == 0) {
        // even grandparent : so need to check for all 4 grandchildren
        if (root->left != nullptr) {
            if (root->left->left != nullptr)
                sum += root->left->left->val;
            if(root->left->right != nullptr)
                sum += root->left->right->val;
        }
        if (root->right != nullptr) {
            if (root->right->left != nullptr)
                sum += root->right->left->val;
            if(root->right->right != nullptr)
                sum += root->right->right->val;
        }

    }
    preorder(root->left, sum);
    preorder(root->right, sum);
}

// main
int sumEvenGrandparent(TreeNode *root) {
    int sum = 0;
    preorder(root, sum);
    return sum;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    cout << sumEvenGrandparent(root);

    return 0;
}