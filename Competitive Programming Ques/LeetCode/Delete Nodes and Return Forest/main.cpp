// Leetcode :: Delete Nodes and Return Forest
// https://leetcode.com/problems/delete-nodes-and-return-forest/

// TC: O(n)
// SC: O(n+n) = 2*O(n) = O(n). Recursion stack and Set

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

// recursive dfs function
TreeNode *helper(TreeNode *root, const unordered_set<int> &toBeDel, vector<TreeNode *> &remaining) {
    // base case
    if (root == nullptr)
        return nullptr;
    // recursive calls : bottom up -> postorder
    root->left = helper(root->left, toBeDel, remaining);
    root->right = helper(root->right, toBeDel, remaining);
    // check if this node is in toBeDel set or not
    if (toBeDel.find(root->val) != toBeDel.end()) {
        // means the set contains the root element : means will have to return null
        // but before returning null, add the children into the remaining array if they aren't null
        if (root->left != nullptr) {
            remaining.push_back(root->left);
        }
        if (root->right != nullptr) {
            remaining.push_back(root->right);
        }
        return nullptr;
    }
    // simply return if not in the set
    return root;
}

vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    // set for easy O(1) access
    unordered_set<int> toBeDel;
    for (auto i: to_delete) {
        toBeDel.insert(i);
    }
    // remaining vector : our ans
    vector<TreeNode *> remaining;
    helper(root, toBeDel, remaining);
    // one corner case : check if the main root is present or not in the set and accordingly place it into the remaining vetor
    if (toBeDel.find(root->val) == toBeDel.end()) {
        // not found in the set : therefore add it into the vector
        remaining.push_back(root);
    }
    // return ans
    return remaining;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    printTree(root);

    vector<int> toBeDel = {3, 5};    // example
    vector<TreeNode *> ans = delNodes(root, toBeDel);

    return 0;
}