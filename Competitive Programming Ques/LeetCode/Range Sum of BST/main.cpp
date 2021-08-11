// Range Sum of BST :: Leetcode
// https://leetcode.com/problems/range-sum-of-bst/

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
            q.push(front->left);
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

// inorder traversal
void inorder(TreeNode *root, int &ans, int low, int high) {
    // base case
    if (root == nullptr)
        return;
    // recursive case
    inorder(root->left, ans, low, high);
    if (root->val >= low && root->val <= high)
        ans += root->val;
    inorder(root->right, ans, low, high);
}

// could do a preorder but it's a bst; so use that
int rangeSumBST(TreeNode *root, int low, int high) {
    int ans = 0;
    inorder(root, ans, low, high);
    return ans;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    // main
    int i, j;
    cin >> i >> j;
    cout << rangeSumBST(root, i, j);
    return 0;
}
