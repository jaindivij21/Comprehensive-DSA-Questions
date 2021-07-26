// Leetcode :: Maximum Level Sum of a Binary Tree
// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

// TC: O(n) :: BFS Traversal
// SC: O(1) :: Constant as we store only the maxSum and currSum

#include<bits/stdc++.h>

using namespace std;

// definition of a node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// building the tree : using BFS
TreeNode *buildTree(TreeNode *&root) {
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

// print the tree : using BFS
void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();
            cout << front->val << " ";
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

// level-wise traversal
void bfs(TreeNode *&root, int &level, int &maxSum) {
    queue<TreeNode *> q;
    level = 1;
    int currLevel = 1;
    maxSum = root->val;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        int currSum = 0;
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();
            currSum += front->val;
            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);
        }
        if (currSum > maxSum) {
            maxSum = currSum;
            level = currLevel;
        }
        currLevel++;
    }
}

// main function
int maxLevelSum(TreeNode *root) {
    int level = 0;
    int maxSum = INT_MIN;
    bfs(root, level, maxSum);   // bfs function
    return level;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    printTree(root);

    cout << maxLevelSum(root);

    return 0;
}