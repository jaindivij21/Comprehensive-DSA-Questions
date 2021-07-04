// All Elements in Two Binary Search Trees :: Leetcode
// https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

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

void inorder(TreeNode *root, vector<int> &v) {
    if (!root) return;
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}

vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2);
    vector<int> ans;
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(ans));
    // Merge function takes log(m+n) as compared with sort function which takes nlogn time.
    return ans;
}

int main() {
    TreeNode *root1 = nullptr;
    TreeNode *root2 = nullptr;
    root1 = buildTree(root1);
    root2 = buildTree(root2);
//    printTree(root);

    vector<int> ans = getAllElements(root1, root2);

    return 0;
}