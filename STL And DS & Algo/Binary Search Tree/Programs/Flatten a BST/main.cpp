// Binary Search Tree
// Flatten a Tree into a linked list using just the tree

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

// make a linked list class that our function will return
template<typename T>
class linkedList {
public:
    node<T> *head;
    node<T> *tail;
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
    queue < node<T> * > q;
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

// Function that flattens the BST
template<typename T>
linkedList<T> flatten(node<T> *root) {
    // make the linked list that stores the ans
    linkedList<T> l;

    // if the tree is empty the linked list will also be empty
    if (root == nullptr) {
        l.tail = l.head = nullptr;
        return l;
    }
    // leaf node/only one node
    if (root->left == nullptr && root->right == nullptr) {
        l.tail = l.head = root;
        return l;
    }
    // left child is present and right is not
    if (root->left != nullptr && root->right == nullptr) {
        // make the left sub tree a linked list
        linkedList<T> leftLL = flatten(root->left);
        // connect is tail to the root adn make root as tail
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
        return l;
    }
    // right child is present and left is not
    if (root->right != nullptr && root->left == nullptr) {
        // make the right sub tree as a linked list
        linkedList<T> rightLL = flatten(root->right);
        // connect the root to the head of the linked list
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
        return l;
    }

    // if both left adn right arent null and are present
    if (root->right != nullptr && root->left != nullptr) {
        // both not null
        // POST ORDER TRAVERSAL -> LEFT RIGHT ROOT
        linkedList<T> leftLL = flatten(root->left);
        linkedList<T> rightLL = flatten(root->right);

        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;

        return l;
    }
}


// main function
int main() {
    // initialize
    node<int> *root = nullptr;

    // build the tree
    cin >> root;
    cout << root;

    linkedList<int> l = flatten(root);
    node<int> *temp = l.head;

    while (temp != nullptr) {
        cout << temp->data << " --> ";
        temp = temp->right;
    }
    cout << endl;

    return 0;
}


