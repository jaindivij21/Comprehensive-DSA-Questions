// Increasing Order Search Tree :: Leetcode
// https://leetcode.com/problems/increasing-order-search-tree/

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
        }
        if (right != -1) {
            front->right = new TreeNode(right);
        }
    }
    return root;
}

// print Tree : bfs (level order)
void printTree(TreeNode *root) {
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

// helper inorder
void inorder(TreeNode *root, TreeNode *&ans, TreeNode *&ptr) {
    // base case
    if (root == nullptr)
        return;
    // recursive cases
    inorder(root->left, ans, ptr);
    ptr->right = new TreeNode(root->val);
    ptr = ptr->right;
    inorder(root->right, ans, ptr);
}

// main
TreeNode *increasingBST(TreeNode *root) {
    TreeNode *ans = new TreeNode(0);
    TreeNode *ptr = ans;
    inorder(root, ans, ptr);
    return ans->right;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    // main
    TreeNode *ans = buildTree(root);
    return 0;
}
