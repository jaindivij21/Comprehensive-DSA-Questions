// Leetcode :: Flip Equivalent Binary Trees
// https://leetcode.com/problems/flip-equivalent-binary-trees/

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
bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    // base case
    if (root1 == nullptr && root2 == nullptr)
        return true;
    if (root1 == nullptr || root2 == nullptr)
        return false;
    // recursive case
    bool ans;
    if (root1->val == root2->val)
        ans = true;
    else
        ans = false;
    // return based on the recursive calls and current root
    // return true if any of the 2 cases possible return true 
    return ans && (flipEquiv(root1->left, root2->left) || flipEquiv(root1->right, root2->left));
}

int main() {
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;
    root1 = buildTree(root1);
    root2 = buildTree(root2);

    if (flipEquiv(root1, root2)) {
        cout << "true";
    } else
        cout << "false";

    return 0;
}