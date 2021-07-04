// Maximum Binary Tree :: Leetcode
// https://leetcode.com/problems/maximum-binary-tree/

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

int findMax(vector<int> &nums, int l, int r) {
    int index = l;
    for (int i = l + 1; i <= r; i++) {
        if (nums[i] >= nums[index])
            index = i;
    }
    return index;
}

TreeNode *makeTree(vector<int> &nums, int start, int end) {
    if (start > end) return nullptr;
    int index = findMax(nums, start, end);
    TreeNode *root = new TreeNode(nums[index]);
    root->left = makeTree(nums, start, index - 1);
    root->right = makeTree(nums, index + 1, end);
    return root;
}


TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return makeTree(nums, 0, nums.size() - 1);
}

int main() {
    TreeNode *root = nullptr;
//    root = buildTree(root);
//    printTree(root);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    TreeNode *ans = constructMaximumBinaryTree(v);
    printTree(ans);
    return 0;
}