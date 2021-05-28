// Binary Search Tree
// Building/Construction of binary tree

#include<iostream>
#include<queue>

using namespace std;

// node class, making it template
template<typename T>
class node {
public:
    T data;
    node *left;
    node *right;

    node(T d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// function to insert a node into the BST
template<typename T>
node<T> *insertInBST(node<T> *root, T d) {
    // base case
    if (root == nullptr) {
        // if root is null then make a new node and insert data in it
        root = new node<T>(d);
        return root;
    } else {
        // Recursive cases
        if (root->data >= d) {
            // will be inserted somewhere in the left subtree
            root->left = insertInBST(root->left, d);
        } else {
            // will be inserted somewhere in the right subtree
            root->right = insertInBST(root->right, d);
        }
    }
    return root;
}

// Builds the BST until it encounters -1 (basically we need an insertion function)
template<typename T>
node<T> *buildBST() {
    // Read numbers till -1 and insert them into the BST
    T d;
    cin >> d;

    // make the root pointing to nullptr
    node<T> *root = nullptr;
    while (d != -1) {
        // insert every node in the bst
        root = insertInBST(root, d);
        cin >> d;
    }
    return root;
}

// prints the binary tree in inorder traversal
template<typename T>
void inorder(node<T> *root) {
    if (root == nullptr) {
        return;
    } else {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}


// prints the binary tree level wise
template<typename T>
void printBfs(node<T> *root) {
    // will use coding blocks null insertion technique to print the tree level wise
    queue<node<T> *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        node<T> *temp = q.front();
        if (temp == nullptr) {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(nullptr);
        } else {
            q.pop();
            cout<<temp->data<<" ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main() {
    cout << "Enter the elements of the binary search tree" << endl;
    node<int> *root = buildBST<int>();

    cout << "Level Order Print:" << endl;
    printBfs(root);

    cout << endl;

    // inorder traversal of a binary search tree will always be sorted
    cout << "Sorted inorder traversal print" << endl;
    inorder(root);
    return 0;
}