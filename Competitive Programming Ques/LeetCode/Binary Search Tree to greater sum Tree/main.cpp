// Binary Search Tree to greater sum Tree :: Leetcode
// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

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

void oppositeInorder(TreeNode *root, int &sum) {
    // base case
    if (root == nullptr)
        return;
    // recursive cases
    oppositeInorder(root->right, sum);
    sum += root->val;
    root->val = sum;
    oppositeInorder(root->left, sum);
}

// The key here is that we need to traverse in such a way that we start from the largest node and then move towards the smallest
// basically the opposite of inorder traversal
TreeNode *bstToGst(TreeNode *root) {
    int sum = 0;
    oppositeInorder(root, sum);
    return root;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    printTree(root);

    TreeNode *ans = bstToGst(root);

    return 0;
}