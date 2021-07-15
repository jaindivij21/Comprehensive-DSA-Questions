// Leetcode :: Maximum Difference Between Node and Ancestor
// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

#include<bits/stdc++.h>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Printing a tree (BFS)
void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    // till the queue isn't empty
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();
            // print the current node
            cout << front->val << " ";
            // Enter the children into the queue
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        cout << endl;
    }
}

// Building a Tree (BFS)
TreeNode *buildTree(TreeNode *root) {
    queue<TreeNode *> q;
    int x;
    cin >> x;
    root = new TreeNode(x);
    q.push(root);
    // while q isn't empty
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

// helper function (postorder)
pair<int, pair<int, int>> dfs(TreeNode *&root) {
    // base case
    if (root == nullptr)
        return make_pair(INT_MIN + 1000, make_pair(INT_MAX - 1000, INT_MIN + 1000));
    // recursive cases
    // get that the 2 pairs from the 2 subtrees
    pair<int, pair<int, int>> leftTree = dfs(root->left);
    pair<int, pair<int, int>> rightTree = dfs(root->right);
    
    // cal the new min, max and ans which will be nothing but the max of ( absolute values of root-min & root-max )
    int mini = min(root->val, min(leftTree.second.first, rightTree.second.first));
    int maxi = max(root->val, max(leftTree.second.second, rightTree.second.second));
    int ans = max(leftTree.first, rightTree.first);
    ans = max(ans, max(abs(root->val - mini), abs(root->val - maxi)));
    
    // return the pair
    return make_pair(ans, make_pair(mini, maxi));
}

// Test Idea
int maxAncestorDiff(TreeNode *root) {
    // pair.first holds the ans while the other pair holds the min max used for intermediate calculations
    pair<int, pair<int, int>> ans = dfs(root);
    return ans.first;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    cout << maxAncestorDiff(root);

    return 0;
}