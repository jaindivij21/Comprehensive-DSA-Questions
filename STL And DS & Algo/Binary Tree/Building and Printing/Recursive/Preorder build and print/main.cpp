// BINARY TREE
// NON LINEAR, HIERARCHICAL DATA STRUCTURE

// Building Binary Tree
// Recursion (PREORDER)

#include<iostream>

using namespace std;

// node that'll help us make the tree
class node {
public:
    int data;
    node *rightChild;
    node *leftChild;

    node(int d) {
        data = d;
        rightChild = nullptr;
        leftChild = nullptr;
    }
};

node *buildTree() {
    int element;
    cin >> element;

    // base case (if user types -1, means stop the tree there)
    if (element == -1)
        return nullptr;
    else {
        node *root = new node(element);
        root->leftChild = buildTree();
        root->rightChild = buildTree();
        return root;
    }
}

void printTree(node *root) {
    if (root == nullptr) {
        return;
    } else {
        cout << root->data << " ";
        printTree(root->leftChild);
        printTree(root->rightChild);
    }
}

int main() {
    cout << "Enter the binary tree" << endl;
    node *root = buildTree();
    cout << "Tree:" << endl;
    printTree(root);

    return 0;
}
