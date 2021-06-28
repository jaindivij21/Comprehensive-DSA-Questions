// Find mode in a binary search Tree : Leetcode
// https://leetcode.com/problems/find-mode-in-binary-search-tree/
// O(1) space complexity : other version can be done easily using map

#include<bits/stdc++.h>

using namespace std;

// tree node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

// preorder tree build
TreeNode *buildTree(TreeNode *root) {
    int element;
    cin >> element;
    if (element == -1)
        return nullptr;
    root = new TreeNode(element);
    root->left = buildTree(root->left);
    root->right = buildTree(root->right);
    return root;
}

void inorder(TreeNode *root, vector<int> &ans, int &prev, int &count, int &max) {
    // base case
    if (root == nullptr)
        return;

    // recursive cases
    inorder(root->left, ans, prev, count, max);

    // if prev is equal to int_min, means it's still not reached the first element
    if (prev != INT_MIN) {
        if (root->val == prev)
            // if root value is eql to prev -> increment the count
            count++;
        else {
            // else if there is a change of element just reset count to 1
            count = 1;
        }
    }
    // updating max and vector
    if (count > max) {
        // if the count gets bigger than prev max : clear the array and reset by adding this val
        max = count;
        ans.clear();
        ans.push_back(root->val);
    }
    else if (count == max) {
        // if new count is eql to the prev max then simply need to append in the array since there can be more than 1 node
        ans.push_back(root->val);
    }
    
    prev = root->val;   // store the curr element into prev, so that it can be used for comparison later

    inorder(root->right, ans, prev, count, max);
}

// its a simple concept, do an inorder traversal of the tree which will be sorted in the order: therefore just cal the mode by traversing the entire O(n)
vector<int> findMode(TreeNode *root) {
    vector<int> ans;
    // global variables
    int prev = INT_MIN;
    int count = 1;  // initialize with 1 because we consider the first element in inorder elready
    int max = 0;
    inorder(root, ans, prev, count, max);
    return ans;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    vector<int> f = findMode(root);
    for (auto i: f)
        cout << i << " ";

    return 0;
}