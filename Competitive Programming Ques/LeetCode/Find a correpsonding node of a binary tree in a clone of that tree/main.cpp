// Find a Corresponding Node of a Binary Tree in a Clone of That Tree :: Leetcode
// https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

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
        int size = q.size();
        for (int i = 0; i < size; i++) {
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

// helper preorder function
void preorder(TreeNode *original, TreeNode *clone, TreeNode *tar, TreeNode *&ans) {
    // base case
    if (original == nullptr)
        return;
    // recursive cases
    if (tar == original) {
        ans = clone;
        return;
    }
    preorder(original->left, clone->left, tar, ans);
    preorder(original->right, clone->right, tar, ans);
}

// will use synchronized traversal
TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
    TreeNode *ans;
    preorder(original, cloned, target, ans);
    return ans;
}

int main() {
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;
    root1 = buildTree(root1);
    root2 = buildTree(root2);

    TreeNode *target;   // fill this

    TreeNode *ans = getTargetCopy(root1, root2, target);

    return 0;
}