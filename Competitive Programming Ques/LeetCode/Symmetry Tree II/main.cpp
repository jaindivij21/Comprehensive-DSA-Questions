// Program to make a binary tree a mirrored Tree i.e. right subtree must be a mirror image of the left sub tree. But all you can do is change values (can't add/delete nodes),
// If the mirror tree isn't possible return/print -1 or print the new tree

// We cannot use STL, if we could have, then this ques could have gotten relatively easy by doing a bfs traversal but longer and tedious code, DFS has a much simpler code.
// Another easy method could have been using the code of inverting a binary tree, which is simple. Roots left subtree could have been inverted and appended to the right of the
// node, however by doing this we would have not have been able to tell if the tree was possible or not in the first place.

#include<bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Printing a tree (BFS)
void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    // till the queue isn't empty
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();
            // print the current node
            cout << front->val << " ";
            // Enter the children into the queue
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

// Building a Tree (BFS)
TreeNode *buildTree(TreeNode *root) {
    queue<TreeNode *> q;
    int x;
    cin >> x;
    root = new TreeNode(x);
    q.push(root);
    // while q isn't empty
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

// main function (bool return type- returns false if the tree cannot be made symmetric else makes it symmetric and returns true)
bool ifSymmetric(TreeNode *left, TreeNode *right) {
    // base case
    if (left == nullptr && right == nullptr)
        return true;    // if both nodes are null, nothing to change, but still can be a symmetric tree so return true
    if (left == nullptr || right == nullptr)
        return false;   // if one of the nodes is null, then there is no way the tree can be mirrored since no of nodes in left and right subtree aren't equal, so return false

    // recursive cases : preorder in both the left subtree and opposite in right sub tree
    if (left->val != right->val)
        right->val = left->val; // if the values in both the trees aren't equal, make them equal, but dont return anything
    //  make recursive calls (both of them) and if they both return true, return true as well
    bool ans1 = ifSymmetric(left->left, right->right);  
    bool ans2 = ifSymmetric(left->right, right->left);  // They were opposite since we are making a mirrored tree
    if (ans1 && ans2) {
        return true;
    }
    return false;
}

// mirror Tree function
TreeNode *mirrorTree(TreeNode *&root) {
    // if the tree cannot be made symmetric : since it doesn't have the same number of nodes return null ptr thus print -1
    if (!ifSymmetric(root->left, root->right)) {
        return nullptr;
    } else {
        // else print the tree
        return root;
    }
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    printTree(root);
    cout << endl;

    // main function
    TreeNode *ans = mirrorTree(root);
    if (ans == nullptr)
        cout << -1 << endl;
    else
        printTree(root);
}

//1 2 2 3 4 4 3 5 6 7 8 8 7 6 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
