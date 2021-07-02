// Merge two binary trees :: Leetcode
// https://leetcode.com/problems/merge-two-binary-trees/

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
        }
        if (right != -1) {
            front->right = new TreeNode(right);
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

// do a simple bfs traversal: level order traversal :: iterative
vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        double avg = 0;
        double count = 0;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *temp = q.front();
            q.pop();
            count++;
            avg += temp->val;
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        avg = avg / count;
        ans.push_back(avg);
    }
}

int main() {
    TreeNode *root1 = nullptr;
    root1 = buildTree(root1);

    // main
    vector<double> ans = averageOfLevels(root1);

    return 0;
}
