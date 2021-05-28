// Binary Search Tree
// Make the BST from preorder traversal

/*
 *  We will do this problem in O(N) time. Will not solve like what we did in main operations. The approach of insertion
 *  will be different. It will be somewhat similar to the problem of making a binary tree using preorder and inorder traversals.
 *
 *  How?
 *  1) Input the pre-order traversal, sort it to get the inorder as well.
 *  2) Keep a pointer from start of preorder and increment it regularly. This determines the *root* of the subtree that we are making.
 *  3) Find this root/node in the inorder array. **Make benefit of the fact that inorder is sorted in BST, i.e. use BINARY SEARCH.
 *  4) Now elements on the right of this root in inorder make up the right sub tree and on the left make up the left subtree.
 *  5) Recursively make the subtrees
 */

#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

// class for node
template<typename T>
class node {
public:
    T data;
    node *left;
    node *right;

    explicit node(T d) {
        data = d;
        right = nullptr;
        left = nullptr;
    }
};

// Print tree Function
template<typename T>
void printTree(node<T> *root) {
    // printing level order (bfs) (Iterative)
    queue<node<T> *> q;
    q.push(root);
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            node<T> *temp = q.front();
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
template<typename T>
ostream &operator<<(ostream &os, node<T> *root) {
    // print tree level wise
    cout << "The tree is:" << endl;
    printTree(root);
    cout << endl;
    return os;
}

// Making a tree using preorder traversal

// normal binary search
template<typename T>
int binarySearch(T in[], T target, int s, int e) {
    if (s >= 0 && e >= 0) {
        int mid = (s + e) / 2;
        if (in[mid] == target) {
            return mid;
        } else if (target > in[mid]) {
            return binarySearch(in, target, mid + 1, e);
        } else {
            return binarySearch(in, target, s, mid - 1);
        }
    }
    return -1;
}

// helper function that does all the work
template<typename T>
node<T> *helper(T pre[], T in[], int s, int e) {
    static int i = 0;   // keeps track of the pre order root value we are on

    // base case
    if (s > e) {
        return nullptr;
    }
    // recursive cases
    // We follow the preorder approach Root-left-right

    // identify the root using preorder and
    node<T> *root = new node<T>(pre[i]);
    // Find this root in the inorder array
    // USE BINARY SEARCH
    int index = binarySearch(in, pre[i], s, e);
    // increment the i pointer i.e. onto the next root
    i++;
    // once the root is assigned, make a call for left and right child of the root
    root->left = helper(pre, in, s, index - 1);
    root->right = helper(pre, in, index + 1, e);
    return root;
}

// main function to make the binary tree suing preorder
template<typename T>
void makeBstUsingPreOrder(node<T> *&root, T pre[], int n) {
    // get the inorder traversal
    T in[n];
    for (int i = 0; i < n; i++) {
        in[i] = pre[i];
    }
    // sort to get the inorder traversal
    sort(in, in + n);
    root = helper(pre, in, 0, n - 1);  // give it the starting and ending indexes of the inorder traversal
}

// main function
int main() {
    // initialize
    node<int> *root = nullptr;

    // build the tree using preorder traversal
    int n;
    cout << "Enter the number of elements in the tree" << endl;
    cin >> n;
    int preOrder[n];
    cout << "Enter the preorder traversal" << endl;
    for (int i = 0; i < n; i++) {
        cin >> preOrder[i];
    }

    // call the main function
    makeBstUsingPreOrder(root, preOrder, n);

    cout << root;

    return 0;
}