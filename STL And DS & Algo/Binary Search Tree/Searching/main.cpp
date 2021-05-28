// Binary Search Tree
// Searching an element in a binary search tree

// The time complexity of search is very efficient in a BST as compared to Normal Binary Tree
// Normal BT: O(N)
// BST: Its worst case time complexity is equal to the height of the tree, therefore if the tree is balanced its O(logN) and if its skewed tree, its O(N)

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
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// Searching
template<typename T>
bool search(node<T> *root, int d) {
    // base cases
    if (root == nullptr) {
        // if the root/tree/subtree is empty means the element doesn't exist
        return false;
    }
    if (d == root->data) {
        // if the curr root is the one we are finding then return true
        return true;
    }

    // Recursive cases
    if (d <= root->data) {
        // data is less than the root, search in the left subtree
        return search(root->left, d);
    } else {
        return search(root->right, d);
    }
}


int main() {
    cout << "Enter the elements of the binary search tree" << endl;
    node<int> *root = buildBST<int>();

    cout << "Level Order Print:" << endl;
    printBfs(root);

    cout << endl;

    // Searching for an element in the tree
    int element;
    cout << "Enter the element to be searched" << endl;
    cin >> element;

    bool ans = search(root, element);
    if (ans)
        cout << "Yes, the element was found" << endl;
    else
        cout << "No, the element was not found" << endl;

    return 0;
}