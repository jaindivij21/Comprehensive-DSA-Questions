// All Possible Full Binary Trees :: Leetcode
// https://leetcode.com/problems/all-possible-full-binary-trees/

// Hard to Medium Problem :: Dynamic Programming (using Recursion and memorization)

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

// global map
unordered_map<int, vector<TreeNode *>> memo;

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

// recursion is very lengthy: memorization can help a little bit
vector<TreeNode *> allPossibleFBT(int n) {
    // vector that stores ans
    vector<TreeNode *> ans;
    // base case
    if (n < 1 || n % 2 == 0) {
        // if n is less than 1 or a multiple of 2: cannot have a FULL binary tree
        return ans;
    }
    if (memo.find(n) != memo.end()) {
        // memo map has something
        return memo[n];
    }
    if (n == 1) {
        // if n is eql to 1 simply return
        ans.push_back(new TreeNode(0));
        memo[1] = ans;
        return ans;
    }


    // main part: including the recursive part
    // get all the possible number of node combinations possible on the left and right sub tree
    for (int i = 1; i < n; i += 2) {
        // incremented i by 2 because if we increment it by 1 : it'll automatically has to anyway get rejected by the base condition
        // make 2 vectors that store the number of nodes in left and right sub tree specifically
        vector<TreeNode *> left = allPossibleFBT(i);
        vector<TreeNode *> right = allPossibleFBT(n - 1 - i);

        // make trees from all possible combinations of left and right subtrees
        for (int j = 0; j < left.size(); j++) {
            for (int k = 0; k < right.size(); k++) {
                TreeNode *root = new TreeNode(0);
                root->left = left[j];
                root->right = right[k];
                ans.push_back(root);
            }
        }
    }
    memo[n] = ans;  // memorize the ans for this integer
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode *> ans = allPossibleFBT(n);
    return 0;
}