// Distribute Coins in Binary Tree :: Leetcode
// https://leetcode.com/problems/distribute-coins-in-binary-tree/
// https://youtu.be/MfXxic8IhkI
// https://leetcode.com/problems/distribute-coins-in-binary-tree/discuss/221939/C%2B%2B-with-picture-post-order-traversal

// Weird Question

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

// helper function
int postorder(TreeNode *root, int &moves) {
    // base case
    if (root == nullptr)
        return 0;
    // recursive case
    int left = postorder(root->left, moves);
    int right = postorder(root->right, moves);
    moves += abs(left) + abs(right);
    return root->val + left + right - 1;
}

// main function
int distributeCoins(TreeNode *root) {
    int moves = 0;
    postorder(root, moves);
    return moves;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    cout << distributeCoins(root);

    return 0;
}