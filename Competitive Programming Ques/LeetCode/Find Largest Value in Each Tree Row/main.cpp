// Leetcode : Find Largest Value in Each Tree Row
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

// Time Complexity : O()

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

// building a tree : Preorder Build
TreeNode *buildTree(TreeNode *&root) {
    int element;
    cin >> element;

    // base case
    if (element == -1)
        return nullptr;
        // recursive case
    else {
        root = new TreeNode(element);
        root->left = buildTree(root->left);
        root->right = buildTree(root->right);
        return root;
    }
}

// bfs : iterative function that makes use of a queue
void bfs(TreeNode *&root, vector<int> &ans) {
    if (root == nullptr) {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        // this loop basically represents each row
        int maxi = INT_MIN;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *temp = q.front();
            q.pop();

            // logic 
            maxi = max(maxi, temp->val);

            // pushing the children of the temp node
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        // after the row ends, add the ans to the vector
        ans.push_back(maxi);
    }
}

// main
vector<int> largestValues(TreeNode *root) {
    vector<int> ans;
    bfs(root, ans);
    return ans;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    vector<int> ans = largestValues(root);
    return 0;
}