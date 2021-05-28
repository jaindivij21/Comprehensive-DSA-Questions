// Binary Search Tree
// Main Functions

#include<iostream>
#include<queue>

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

// insert element into the BST
template<typename T>
node<T> *insertInBST(node<T> *&root, T element) {
    // base case
    if (root == nullptr) {
        root = new node<T>(element);
        return root;
    }
    // recursive cases
    if (root->data >= element) {
        root->left = insertInBST(root->left, element);
    } else {
        root->right = insertInBST(root->right, element);
    }
    return root;
}

// build Tree Function
template<typename T>
void buildTree(node<T> *&root) {
    cout << "Enter the tree (BST) elements" << endl;
    T element = 0;
    while (element != -1) {
        cin >> element;
        if (element != -1)
            root = insertInBST(root, element);
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
        // finding inorder successor
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


// main function
int main() {
    // initialize
    node<int> *root = nullptr;

    // build the tree
    cin >> root;
    cout << root;

    // insertion
    cout << "Enter the element to insert" << endl;
    int ele;
    cin >> ele;
    root = insertInBST(root, ele);

    cout << root;

    // deletion
    cout << "Enter element to be deleted" << endl;
    int delElem;
    cin >> delElem;
    root = deleteInBST(root, delElem);
    cout << root;

    return 0;
}


