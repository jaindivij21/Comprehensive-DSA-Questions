// Delete Leaves With a Given Value :: Leetcode
// https://leetcode.com/problems/delete-leaves-with-a-given-value/

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

// main function :: postorder traversal -> since we need to delete operation after we have visited the nodes below it
TreeNode *removeLeafNodes(TreeNode *root, int target) {
    // base case
    if (root == nullptr)
        return nullptr;
    // recursive cases
    root->left = removeLeafNodes(root->left, target);
    root->right = removeLeafNodes(root->right, target);
    // operation
    if (root->val == target && root->left == nullptr && root->right == nullptr)
        return nullptr;
    return root;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    int target;
    cin >> target;

    TreeNode *ans = removeLeafNodes(root, target);
    printTree(ans);

    return 0;
}