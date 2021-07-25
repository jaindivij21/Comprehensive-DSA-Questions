// Leetcode :: Maximum Binary Tree II
// https://leetcode.com/problems/maximum-binary-tree-ii/

/*
 *  Basically since the element is appended at the end of the list, all the elements smaller than it will be in its
 *  left sub tree.
 */

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

// main function
TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
    // base cases
    if (root == nullptr)
        return new TreeNode(val);   // if root is null, just return the root with val as element
    // if the val is greater than the root's val :  than the entire tree becomes the left subtree of our element 
    if (root->val <= val) {
        auto* ans = new TreeNode(val);
        ans->left = root;
        return ans;
    }
    // recursive case : else the value will be inserted somewhere in the right subtree : use recursion for the same
    else
        root->right = insertIntoMaxTree(root->right, val);  
    // return the root
    return root;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    printTree(root);
    int val;
    cin >> val;
    TreeNode *ans = insertIntoMaxTree(root, val);
    return 0;
}