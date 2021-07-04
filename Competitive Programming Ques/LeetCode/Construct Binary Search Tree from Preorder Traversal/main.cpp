// Construct Binary Search Tree from Preorder Traversal :: Leetcode
// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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

void preorder(TreeNode *&root, int value) {
    // base case
    if (root == nullptr) {
        root = new TreeNode(value);
        return;
    }
    // recursive cases
    if (root->val > value)
        preorder(root->left, value);
    if (root->val < value)
        preorder(root->right, value);
}

TreeNode *bstFromPreorder(vector<int> &arr) {
    TreeNode *root = new TreeNode(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        int val = arr[i];
        preorder(root, val);
    }
    return root;
}

int main() {
    TreeNode *root = nullptr;
//    root = buildTree(root);
//    printTree(root);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    TreeNode *ans = bstFromPreorder(v);
    printTree(ans);

    return 0;
}