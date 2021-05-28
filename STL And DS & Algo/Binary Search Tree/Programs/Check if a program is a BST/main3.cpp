// Binary Search Tree
// Tell if a tree is a binary search tree

// Top Down Approach

#include<iostream>
#include<queue>
#include<climits>

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

template<typename T>
// build Tree (Normal Tree (Not BST)) Function
void buildTree(node<T> *&root) {
    int element;
    cin >> element;
    queue<node<T> *> q;
    root = new node<T>(element);
    q.push(root);
    while (!q.empty()) {
        node<T> *temp = q.front();
        q.pop();
        int left, right;
        cin >> left >> right;
        if (left != -1) {
            temp->left = new node<T>(left);
            q.push(temp->left);
        }
        if (right != -1) {
            temp->right = new node<T>(right);
            q.push(temp->right);
        }
    }
}

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

// deletion Function
template<typename T>
node<T> *deleteInBST(node<T> *root, T data) {
    if (root == nullptr) {
        return nullptr;
    } else if (data < root->data) {
        root->left = deleteInBST(root->left, data);
        return root;
    } else if (data == root->data) {
        // 1) 0 children
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        // 2) 1 child
        if (root->left != nullptr && root->right == nullptr) {
            node<T> *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr) {
            node<T> *temp = root->right;
            delete root;
            return temp;
        }
        // 3) 2 children
        node<T> *replace = root->right;
        while (replace->left)
            replace = replace->left;
        root->data = replace->data;
        deleteInBST(root->right, replace->data);
        return root;
    } else {
        root->right = deleteInBST(root->right, data);
        return root;
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

template<typename T>
istream &operator>>(istream &is, node<T> *&root) {
    // build tree level wise
    buildTree(root);
    return is;
}

// function to check if the tree is bst
// TOP DOWN APPROACH
template<typename T>
bool isBST(node<T> *root, int minV = INT_MIN, int maxV = INT_MAX) {
    // base case
    // if the tree is empty or after last node return true
    if (root == nullptr)
        return true;
    // recursive cases
    // Preorder Root-left-right
    // for every root check if its more than its minV and less than maxValue
    // also call left and right child of the root i.e. if they are bst or not by changing their min and max value
    if (root->data >= minV && root->data <= maxV && isBST(root->left, minV, root->data) && isBST(root->right, root->data, maxV)) {
        // if all are true, return true
        return true;
    }
    // if none of the above is true, return false
    return false;
}

// main function
int main() {
    // initialize
    node<int> *root = nullptr;

    // build the tree
    cin >> root;
    cout << root;

    // function to check if the tree is a binary search tree
    bool ans = isBST(root);

    // print results
    if (ans)
        cout << "Yes, its a binary tree" << endl;
    else
        cout << "No, its not a binary tree" << endl;


    return 0;
}


