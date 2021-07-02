// Construct String from binary tree :: Leetcode
// https://leetcode.com/problems/construct-string-from-binary-tree/

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

// helper function
void preorder(TreeNode *root, string &ans) {
    // base case
    if (root == nullptr)
        return;
    // recursive cases
    ans.append("(" + to_string(root->val));
    preorder(root->left, ans);
    if (root->right && !root->left)
        ans.append("()");
    preorder(root->right, ans);
    ans.append(")");
}

// main function
string tree2str(TreeNode *root) {
    string ans;
    preorder(root, ans);
    return string(ans.begin() + 1, ans.end() - 1);
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    printTree(root);

    // main
    string ans = tree2str(root);
    cout << ans;

    return 0;
}
