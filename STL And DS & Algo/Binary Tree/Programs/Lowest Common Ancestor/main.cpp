// Binary Tree
// Program to find the lowest common ancestor node of 2 nodes
// https://www.youtube.com/watch?v=w8rr1AYMlfw
/*
 *  There can be many methods:
 *  1) for each node find paths to the root and then traverse through those paths to check for first common node
 *  2) find height of both nodes, get the difference. when height is same, increment both by one parent. when both point to same, that's the ans
 *  3) the fact that a node is the ancestor if one node lies in its left sub tree and one in its right subtree
 */

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

// Function execution
// Recursive Solution
// based on the fact that root will be LCA if a nd b are on 2 opposite sides of root
// Root-left-right
// assume keys are unique
node *lowAnc(node *root, int a, int b) {
    // base cases
    if (root == nullptr) {
        return nullptr; // means tree is empty
    }
    if (root->data == a || root->data == b) {
        return root;    // if the root itself is any one of the data, then it will be the lca
    }

    // recursive cases
    // search in left and right sub trees
    node *leftAns = lowAnc(root->left, a, b);
    node *rightAns = lowAnc(root->right, a, b);

    // if both return NOT null means they are returning some node's address
    // this means a and b both lie in left and right sub tree respectively, hence lca
    if (leftAns != nullptr && rightAns != nullptr) {
        return root;
    }
    // if how ever only left sub tree returns not null val, means a has been found but not b 
    if (leftAns != nullptr) {
        return leftAns;
    }
    //     // if how ever only right sub tree returns not null val, means b has been found but not a
    return rightAns;
}


// main function
int main() {
    node *root = nullptr;
    cin >> root;
    cout << root;

    // main program
    cout << "Enter the elements from the tree whose lowest ancestor is to be found" << endl;
    int a, b;
    cin >> a >> b;
    cout << "The lowest ancestor is: " << lowAnc(root, a, b)->data << endl;

    return 0;
}