// Balance a Binary Search Tree :: Leetcode
// https://leetcode.com/problems/balance-a-binary-search-tree/

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

// inorder traversal function
void inorder(TreeNode *root, vector<int> &sorted) {
    // base case
    if (root == nullptr)
        return;
    // recursive case
    inorder(root->left, sorted);
    sorted.push_back(root->val);
    inorder(root->right, sorted);
}

// building the height balanced tree from the array
TreeNode *buildHeightBalancedTree(vector<int> &sorted, int left, int right) {
    // base case
    if (left > right)
        // no node left
        return nullptr;
    // recursive cases
    int mid = left + (right - left) / 2;
    TreeNode *root = new TreeNode(sorted[mid]);
    root->left = buildHeightBalancedTree(sorted, left, mid - 1);
    root->right = buildHeightBalancedTree(sorted, mid + 1, right);
    return root;
}

// main function
TreeNode *balanceBST(TreeNode *root) {
    vector<int> sorted;
    inorder(root, sorted);
    // now we have the sorted array in our vector and using that we need to build the height balanced binary tree
    return buildHeightBalancedTree(sorted, 0, sorted.size() - 1);
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    TreeNode *ans = balanceBST(root);
    printTree(ans);

    return 0;
}