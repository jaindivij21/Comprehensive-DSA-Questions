// BINARY TREE
// NON LINEAR, HIERARCHICAL DATA STRUCTURE

// Building Binary Tree
// Level wise O(N2) Recursion

#include<iostream>
#include<queue>

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

// build tree using pre order
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

int height(node *root) {
    // base case
    if (root == nullptr)
        return 0;
    // recursive cases
    int leftChildHeight = height(root->leftChild);
    int rightChildHeight = height(root->rightChild);
    return max(leftChildHeight, rightChildHeight) + 1;
}

void printkthlevel(node *root, int k) {
    // basically we print the kth level
    if (root == nullptr) {
        // node not present
        return;
    }
    if (k == 1) {
        // if we reached the level that needs to be printed we print it
        cout << root->data << " ";
        return;
    }

    // if we yet haven't reached the level that needs to be printed, we call its child's
    printkthlevel(root->leftChild, k - 1);
    printkthlevel(root->rightChild, k - 1);
}

void printLevelOrder(node *root) {
    for (int i = 1; i <= height(root); i++) {
        printkthlevel(root, i);
        cout << endl;
    }
}

int main() {
    cout << "Enter the binary tree" << endl;
    node *root = buildTree();

    cout << "Tree:" << endl;
    cout << "LevelOrder: " << endl;
    printLevelOrder(root);

    return 0;
}
