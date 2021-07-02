// Sum of Root To Leaf Binary Numbers :: Leetcode
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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

// helper function preorder traversal
void preorder(TreeNode *root, int &ans, int num) {
    // base case
    if (root == nullptr)
        return;
    // recursive cases
    num = num << 1;
    num = num | root->val;
    if (root->left == nullptr && root->right == nullptr) {
        // leaf node
        ans += num;
    }
    preorder(root->left, ans, num);
    preorder(root->right, ans, num);
}

// simple dfs :: preorder
int sumRootToLeaf(TreeNode *&root) {
    int ans = 0;
    int num = 0;
    preorder(root, ans, num);
    return ans;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    // main
    int ans = sumRootToLeaf(root);
    cout << ans << endl;
    return 0;
}
