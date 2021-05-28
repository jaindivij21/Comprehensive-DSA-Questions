// Binary Tree
// Print the right view

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// class for node
class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        right = nullptr;
        left = nullptr;
    }
};

// build Tree level order
void buildTree(node *&root) {
    // input the root node
    int element;
    cin >> element;
    // make the queue
    queue<node *> q;

    // make the root node and push it into the queue
    root = new node(element);
    q.push(root);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();
        int left, right;
        cin >> left >> right;
        if (left != -1) {
            temp->left = new node(left);
            q.push(temp->left);
        }
        if (right != -1) {
            temp->right = new node(right);
            q.push(temp->right);
        }
    }
}

// prints the right view of the tree recursively
// top to bottom traversal (root->right->left) and print when on the right node. However we only print the first time when we reach a new level's right
void rightView(node *root, int level, int &maxLevel) {
    // base cases
    // passing max level by reference since its value should not reset
    if (root == nullptr)
        return;
    if (maxLevel < level) {
        // this means this is a new level not yet encountered, and since we first visit right child, we have to print this
        maxLevel = level;   // update the value of max level
        cout << root->data << " ";
    }

    // recursive cases
    // first right, then left
    rightView(root->right, level + 1, maxLevel);
    rightView(root->left, level + 1, maxLevel);
}

// main function
int main() {
    node *root = nullptr;
    buildTree(root);

    int maxLevel = -1;
    rightView(root, 0, maxLevel);

    return 0;
}