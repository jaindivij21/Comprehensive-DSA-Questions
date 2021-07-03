// Deepest Leaves Sum :: Leetcode
// https://leetcode.com/problems/deepest-leaves-sum/

// This solution uses DFS: Easy to write but slow abit. 

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

// cal and returns the height of the tree
int heightOfTree(TreeNode *root) {
    // base case
    if (root == nullptr)
        return 0;
    // recursive cases
    return (max(heightOfTree(root->left), heightOfTree(root->right)) + 1);
}

// preorder traversal : whenever the count becomes equal to the height of the tree, add that number to the sum
void preorder(TreeNode *root, int &sum, int &count, int height) {
    // base case
    if (root == nullptr) {
        return;
    }
    if (count == height) {
        sum += root->val;
    }
    // recursive cases
    count++;    // increase count when going down
    preorder(root->left, sum, count, height);
    preorder(root->right, sum, count, height);
    count--;    // decrease count when backtracking/going back up
}

// main
int deepestLeavesSum(TreeNode *root) {
    int height = heightOfTree(root);
    // now do a preorder traversal and add up the sum of nodes at this height
    int sum = 0;
    int count = 1;
    preorder(root, sum, count, height);
    return sum;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    cout << deepestLeavesSum(root);

    return 0;
}