// Program to check if a tree is height balanced or not
/*
 * Naive Approach: would be to calculate height of the sub trees at each node, subtract them and check if they are
 * balanced, but this makes time complexity O(n2).
 *
 * Better Approach:
 * Bottom up approach i.e. Postorder (L-R-Root).
 */

#include<iostream>
#include<math.h>

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

class Pair {
public:
    bool ifBalanced;
    int height;
};

// bottom up approach
Pair checkBalanced(node *root) {
    Pair p{};

    // base case
    if (root == nullptr) {
        p.height = 0;
        p.ifBalanced = true;
        return p;
    }
    // recursive cases (PostOrder)
    Pair right = checkBalanced(root->right);
    Pair left = checkBalanced(root->left);

    // heights of subtrees
    int leftHeight = left.height;
    int rightHeight = right.height;

    // height of current node
    p.height = max(leftHeight, rightHeight) + 1;

    // check if balanced
    if (abs(leftHeight - rightHeight) <= 1 && left.ifBalanced && right.ifBalanced) {
        p.ifBalanced = true;
    } else {
        p.ifBalanced = false;
    }
    return p;
}


int main() {
    // building the tree
    cout << "Enter the tree (Preorder)" << endl;
    node *root = buildTree();

    Pair ans = checkBalanced(root);
    if (ans.ifBalanced)
        cout << "Yes, It's balanced" << endl;
    else
        cout << "No. It's not balanced" << endl;
    return 0;
}