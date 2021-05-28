// Program to calculate the diameter of a binary tree

#include<iostream>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// preorder build
node *buildTree() {
    int element;
    cin >> element;

    if (element == -1)
        return nullptr;
    else {
        node *root = new node(element);
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
}

int height(node *root) {
    // base case
    if (root == nullptr)
        return 0;
    // recursive cases
    int leftChildHeight = height(root->left);
    int rightChildHeight = height(root->right);
    return max(leftChildHeight, rightChildHeight) + 1;
}

int main() {
    // building the tree
    cout << "Enter the tree (Preorder)" << endl;
    node *root = buildTree();

    // height of the tree
    cout << "The height of this tree is: " << height(root) << endl;


    return 0;
}