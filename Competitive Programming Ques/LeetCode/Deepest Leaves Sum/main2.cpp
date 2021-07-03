// Deepest Leaves Sum :: Leetcode
// https://leetcode.com/problems/deepest-leaves-sum/

// uses BFS

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
        int size = q.size();
        for (int i = 0; i < size; i++) {
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

void bfs(TreeNode *root, int &sum) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        sum = 0;
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();
            sum += front->val;
            if (front->left != nullptr)
                q.push(front->left);
            if (front->right != nullptr)
                q.push(front->right);
        }
    }
}

int deepestLeavesSum(TreeNode *root) {
    int sum = 0;
    bfs(root, sum);
    return sum;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    cout << deepestLeavesSum(root);

    return 0;
}