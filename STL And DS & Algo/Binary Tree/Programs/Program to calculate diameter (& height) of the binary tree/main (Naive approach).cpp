// Program to calculate the diameter of a binary tree
// Naive Approach (O(n2))

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

// function to cal the height
int height(node *root) {
    if (root == nullptr)
        return 0;
    int leftH = height(root->left);
    int rightH = height(root->right);
    return max(rightH, leftH) + 1;
}

int diameter(node *root) {
    // base case
    if (root == nullptr)
        return 0;

    int leftTreeHeight = height(root->left);
    int rightTreeHeight = height(root->right);

    // if the diameter passes through the root
    int possibleDia1 =  leftTreeHeight + rightTreeHeight;
    // if the diameter lies in the left sub tree
    int possibleDia2 = diameter(root->left);
    // if the diameter lies in the right sub tree
    int possibleDia3 = diameter(root->right);

    return max(possibleDia1, max(possibleDia2, possibleDia3));
}

int main() {
    // building the tree
    cout << "Enter the tree (Preorder)" << endl;
    node *root = buildTree();

    // diameter of the tree
    cout << "The diameter of this tree is: " << diameter(root) << endl;


    return 0;
}