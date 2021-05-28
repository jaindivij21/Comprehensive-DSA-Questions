// Count number of nodes in the tree
// To Calculate the sum of all the nodes in the tree

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

int count(node *root) {
    if (root == nullptr)
        return 0;
    else
        return 1 + count(root->left) + count(root->right);
}

int sum(node *root) {
    if (root == nullptr)
        return 0;
    else
        return root->data + sum(root->left) + sum(root->right);
}


int main() {
    // building the tree
    cout << "Enter the tree (Preorder)" << endl;
    node *root = buildTree();

    // to count the number of nodes you can choose any type of transversal
    cout << "Number of nodes: " << count(root) << endl;
    cout << "Sum of nodes: " << sum(root) << endl;

    return 0;
}