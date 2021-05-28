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

// bottom up (optimized approach)
/*
 *  Basically we maintain a pair of height and diameter for every node (uptil that node)
 *  Also, we know the bottom up approach is the post order traversal. So that is what we'll follow!
 *  Basically earlier it took O(n) to cal just the height of nodes at each level, and then the diameter thus making complexity O(n2)
 *  BUT, now we made a pair of both, thus calculating both height and diameter together side by side.
 */

class Pair {
public:
    int height;
    int diameter;
};

// better approach
Pair fastHeightAndDiameter(node *root) {
    // make pair object for current root 
    Pair p{};
    if (root == nullptr) {
        p.diameter = 0;
        p.height = 0;
        return p;
    } else {
        Pair left = fastHeightAndDiameter(root->left);
        Pair right = fastHeightAndDiameter(root->right);
        p.height = max(left.height, right.height) + 1;
        p.diameter = max(left.height + right.height, max(left.diameter, right.diameter));
        return p;
    }
}

int main() {
    // building the tree
    cout << "Enter the tree (Preorder)" << endl;
    node *root = buildTree();

    // diameter and height of the tree
    cout << "The diameter of this tree is: " << fastHeightAndDiameter(root).diameter << endl;
    cout << "The height of this tree is: " << fastHeightAndDiameter(root).height << endl;


    return 0;
}