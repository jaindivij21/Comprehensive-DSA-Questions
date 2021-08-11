// Leetcode :: Subtree of Another Tree
// https://leetcode.com/problems/subtree-of-another-tree/

// Time Complexity : O(n*m) for the worst case

#include<bits/stdc++.h>

using namespace std;

// Tree Node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

// helper function : checks if the 2 subtrees match exactly
bool ifOk(TreeNode *root, TreeNode *subRoot) {
    // base case
    if (root == nullptr && subRoot == nullptr)
        return true;
    // recursive case
    bool ans = false;
    if (root!= nullptr && subRoot != nullptr && root->val == subRoot->val)
        ans = true;
    return ans && ifOk(root->left, subRoot->left) && ifOk(root->right, subRoot->right);
}

// main function : does a dfs traversal over the main tree
bool isSubtree(TreeNode *root, TreeNode *subRoot) {
    // base case
    if (root == nullptr) {
        return false;
    }
    // recursive case
    bool ans = false;
    if (root->val == subRoot->val) {
        // if the root values match, checks if the subtree also matches exactly
        ans = ifOk(root, subRoot);
    }
    bool left = isSubtree(root->left, subRoot);
    bool right = isSubtree(root->right, subRoot);
    return ans || left || right;
}

int main() {
    TreeNode *root = nullptr;
    TreeNode *subRoot = nullptr;
    root = buildTree(root);
    subRoot = buildTree(subRoot);

    cout << isSubtree(root, subRoot);

    return 0;
}