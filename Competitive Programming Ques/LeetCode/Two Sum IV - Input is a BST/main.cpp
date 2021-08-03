// Leetcode: Two Sum IV - Input is a BST
// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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

bool dfs(TreeNode *root, set<int> &s, int k) {
    // base case
    if (root == nullptr)
        return false;
    // recursive cases
    // add to the has map
    bool temp = false;
    // change the value of temp if complementary exists in set
    if (s.find(root->val) != s.end()) {
        temp = true;
    }
    // if the complimentary isn't present in set, then add it to the set
    if (s.find(k - root->val) == s.end()) {
        s.insert(k - root->val);
    }
    // calls
    return temp || dfs(root->left, s, k) || dfs(root->right, s, k);
}

// easy to do by using extra space i.e. hashtable
bool findTarget(TreeNode *root, int k) {
    set<int> s;
    return dfs(root, s, k);
}

int main() {

    return 0;
}