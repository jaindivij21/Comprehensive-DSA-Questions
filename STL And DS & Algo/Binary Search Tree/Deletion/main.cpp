// Binary Search Tree
// Deletion Operation

#include<iostream>
#include<vector>
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
/*
 *  There can be 3 cases in deletion:
 *  The node to be deleted can have ->
 *  1) 0 children
 *  2) 1 child
 *  3) 2 children
 */
template<typename T>
node<T> *deleteInBST(node<T> *root, T data) {
    // step 1 is to find the node
    if (root == nullptr) {
        // if we reach the end of the tree, we return null
        return nullptr;
    } else if (data < root->data) {
        // if data is less than root, we try to find it in left subtree
        root->left = deleteInBST(root->left, data);
        return root;
    } else if (data == root->data) {
        // found the node to delete (3 cases)

        // 1) 0 children
        if (root->left == nullptr && root->right == nullptr) {
            // means the node has no children
            delete root;
            return nullptr;
        }
        // 2) 1 child
        if (root->left != nullptr && root->right == nullptr) {
            // only left child exists
            node<T> *temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == nullptr && root->right != nullptr) {
            // only right child exists
            node<T> *temp = root->right;
            delete root;
            return temp;
        }
        // 3) 2 children
        /*
         *  In this case of a node having 2 children, when its deleted its always replaced
         *  by either its inorder successor or inorder predecessor i.e. min node on RHS and
         *  max node on the LHS of the node to be deleted in Inorder Traversal!
         *
         *  In this problem we'll implement inorder successor. For a root node, its inorder successor
         *  would be found when you keep on going towards left of the right child of the root node.
         *  Make tree to understand.
         */
        node<T> *replace = root->right;
        while (replace->left)
            replace = replace->left;
        // now replace points to inorder successor of the root node
        root->data = replace->data; // changed the data of root data as replace data
        // now we need to delete the replace node but also manage (if it has) its children nodes
        // We'll manage them recursively (i.e. call for its deletion)
        deleteInBST(root->right, replace->data);
        // return ans
        return root;
    } else {
        // if data is more than root, we try to find it in right subtree
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

    // deletion
    cout << "Enter element to be deleted" << endl;
    int delElem;
    cin >> delElem;
    root = deleteInBST(root, delElem);
    cout << root;

    return 0;
}


