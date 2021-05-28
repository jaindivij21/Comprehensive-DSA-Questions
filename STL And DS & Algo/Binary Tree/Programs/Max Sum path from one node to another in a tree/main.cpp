// Binary Tree
// Program to find the max sum of path from any node to any node in the binary tree
// Solving using recursion

// DRAW TREE TO UNDERSTAND

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

// build Tree Function
void buildTree(node *&root) {
    int element;
    cin >> element;
    queue<node *> q;
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

// Print tree Function
void printTree(node *root) {
    queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            node *temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
        cout << endl;
    }
}

// operator overloading
ostream &operator<<(ostream &os, node *root) {
    // print tree level wise
    cout << "The tree is:" << endl;
    printTree(root);
    return os;
}

istream &operator>>(istream &is, node *&root) {
    // build tree level wise
    cout << "Enter the contents of the tree" << endl;
    buildTree(root);
    return is;
}

/*
 *  Approach will be:
 *  The max sum path can pass through the root, only in the left subtree or only in the right subtree.
 *  So for each node maintain a maxSumPath and also maxBranchSum
 */

// helper class to store each node's maxSum and branchMaxSum
class Pair {
public:
    int maxSum;
    int branchSum;

    Pair() {
        maxSum = 0;
        branchSum = 0;
    }
};

// Main function to cal the maxSumPath
// Post order traversal -> LRr
Pair maxSum(node *root) {
    Pair p; // pair which will store the node's max sum and max branch sum

    // base case
    if (root == nullptr) {
        // the root/tree/subtree doesnt exist
        return p;
    }

    // recursive cases (complex)
    // they calculate everything for left and right subtrees
    Pair left = maxSum(root->left);
    Pair right = maxSum(root->right);

    // Root
    // firstly calculate the maxSum which passes through this root (this will make use of branch max sums)
    int op1 = root->data;   // only the root
    int op2 = left.branchSum + root->data;  // max path sum for this node is root + maximum branchSum in left tree
    int op3 = right.branchSum + root->data;  // max path sum for this node is root + maximum branchSum in right tree
    int op4 = left.branchSum + right.branchSum + root->data;  //  root + maximum branchSum in right tree nd left tree

    // this is the maxSum path for current node if that path passes through this node
    int currNodeMaxSumPath = max(op1, max(op2, max(op3, op4)));

    // the max branch sum for curr node (will pe passed to parent nodes)
    p.branchSum = root->data + max(left.branchSum, right.branchSum);
    // ANSWER: the max sum path for current node:: may pass through left, right and root, or just in left subtree
    // or just the right subtree
    p.maxSum = max(currNodeMaxSumPath, max(right.maxSum, left.maxSum));

    return p;
}

// main function
int main() {
    node *root = nullptr;
    cin >> root;
    cout << root;

    // main program
    cout << "The max sum path in the binary tree iss: " << maxSum(root).maxSum << endl;

    return 0;
}