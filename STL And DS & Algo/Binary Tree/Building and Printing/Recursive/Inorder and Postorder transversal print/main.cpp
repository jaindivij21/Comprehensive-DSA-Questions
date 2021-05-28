// BINARY TREE
// NON LINEAR, HIERARCHICAL DATA STRUCTURE

// Building and printing Binary Tree
// Recursion

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

// build tree using preorder
node *buildPreTree() {
    int element;
    cin >> element;

    // base case (if user types -1, means stop the tree there)
    if (element == -1)
        return nullptr;
    else {
        node *root = new node(element);
        root->leftChild = buildPreTree();
        root->rightChild = buildPreTree();
        return root;
    }
}

// print in all the types of transversal
void printPreOrder(node *root) {
    if (root == nullptr) {
        return;
    } else {
        cout << root->data << " ";
        printPreOrder(root->leftChild);
        printPreOrder(root->rightChild);
    }
}

void printPostOrder(node *root) {
    if (root == nullptr) {
        return;
    } else {
        printPostOrder(root->leftChild);
        printPostOrder(root->rightChild);
        cout << root->data << " ";
    }
}

void printInorder(node *root) {
    if (root == nullptr)
        return;
    else {
        printInorder(root->leftChild);
        cout << root->data << " ";
        printInorder(root->rightChild);
    }
}


int main() {
    cout << "Enter the binary tree" << endl;
    node *root = buildPreTree();
    cout << "Tree:" << endl;
    cout << "\nPreorder: ";
    printPreOrder(root);
    cout << "\nInorder: ";
    printInorder(root);
    cout << "\nPostorder: ";
    printPostOrder(root);

    return 0;
}
