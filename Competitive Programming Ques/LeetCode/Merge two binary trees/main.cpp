// Merge two binary trees :: Leetcode
// https://leetcode.com/problems/merge-two-binary-trees/

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

// do a simple preorder traversal and merge both the trees into the first one itself
TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    // base case
    if (root1 == nullptr)
        return root2;
    if (root2 == nullptr)
        return root1;
    // recursive cases
    root1->val += root2->val;   // add the values at the root
    root1->left = mergeTrees(root1->left, root2->left); // call left and right sub tree
    root1->right = mergeTrees(root1->right, root2->right);
    return root1;   // return the root tree
}

int main() {
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;
    root1 = buildTree(root1);
    root2 = buildTree(root2);

    // main
    TreeNode *ans = mergeTrees(root1, root2);
    printTree(ans);

    return 0;
}
