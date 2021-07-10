// Find Elements in a Contaminated Binary Tree :: Leetcode
// https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
void printTree(TreeNode *&root) {
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

// answer class
class FindElements {
    // global set
    set<int> values;
public:
    // helper function for FindElements constructor : preorder traversal that sets the root value acc to the requirement
    // flag variable decides if its the left or right child
    void helper(TreeNode *&root, TreeNode *prev, int flag) {
        // base case
        if (root == nullptr)
            return;
        // recursive case
        if (flag == 0)
            // left child
            root->val = 2 * prev->val + 1;
        if (flag == 1)
            root->val = 2 * prev->val + 2;
        values.insert(root->val);
        prev = root;    // update the previous node
        // calls
        helper(root->left, prev, 0);
        helper(root->right, prev, 1);
    }

    // constructor : change the contaminated tree into recovered tree
    explicit FindElements(TreeNode *&root) {
        // set the first val to 0, initialize prev node, and finally recursive call to left and right sub tree
        root->val = 0;
        values.insert(0);
        TreeNode *prev = root;
        helper(root->left, prev, 0);
        helper(root->right, prev, 1);
    }

    // method that finds the target : do a normal traversal
    bool find(int target) {
        if (values.find(target) != values.end())
            return true;
        else
            return false;
    }
};

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    int target;
    cin >> target;

    auto *obj = new FindElements(root);
    bool param_1 = obj->find(target);
    printTree(root);
    cout << endl;
    cout << param_1;

    return 0;
}