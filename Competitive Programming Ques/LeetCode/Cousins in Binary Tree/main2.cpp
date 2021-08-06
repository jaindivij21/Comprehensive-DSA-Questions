// Leetcode : Cousins in Binary Tree
// https://leetcode.com/problems/cousins-in-binary-tree/

// IMPORTANT: This is a variation of this above problem: This ans is for the ques: Real and Far Cousins in BT, since it consider siblings and cousins both at the same depth.

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(TreeNode *root) {
    int ele;
    cin >> ele;

    if (ele == -1)
        return nullptr;
    else {
        auto *temp = new TreeNode(ele);
        temp->left = buildTree(temp->left);
        temp->right = buildTree(temp->right);
        return temp;
    }
}

void preorder(TreeNode *root, int x, int y, bool &ans, int &h, int depth) {
    // base case
    if (root == nullptr)
        return;

    // recursive cases
    // this if statement must come before the other one
    if (h != -1 && root->val == x || root->val == y) {
        if (h == depth) {
            ans = true;
        }
    }

    if (h == -1 && root->val == x || root->val == y) {
        h = depth;
    }

    preorder(root->left, x, y, ans, h, depth + 1);
    preorder(root->right, x, y, ans, h, depth + 1);
}

// 2 easy ways to do this: use BFS and check if they are in same row, or use DFS and check height. I'll use latter cuz it's slightly complex but less efficient.
bool isCousins(TreeNode *root, int x, int y) {
    bool ans = false;
    int h = -1;
    int depth = 0;
    preorder(root, x, y, ans, h, depth);
    return ans;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    int x, y;
    cin >> x >> y;
    cout << isCousins(root, x, y);

    return 0;
}