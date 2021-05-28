// Binary Tree
// Program to print k level far nodes from a given node
// GOOD PROBLEM
// https://www.youtube.com/watch?v=B89In5BctFA

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

// class node
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

// building the tree
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

// printing the tree
void bfsTraversal(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        node *temp = q.front();
        if (temp == nullptr) {
            cout << endl;
            q.pop();
            if (!q.empty())
                q.push(nullptr);
        } else {
            cout << temp->data << " ";
            q.pop();
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// helper
// finding a node and returning its path till root
// given data, root node and a vector, it returns in the vector the path from the data node to root node
bool pathFromRoot(int data, node *root, vector<node *> &v) {
    // base case
    if (root == nullptr)
        return false;
    if (root->data == data) {
        // since it returns true, and the data node has been found, push into the vector
        v.push_back(root);
        return true;
    }

    // recursive cases
    bool ifFoundInLeftSubtree = pathFromRoot(data, root->left, v);
    if (ifFoundInLeftSubtree) {
        v.push_back(root);
        return true;
    }
    bool ifFoundInRightSubtree = pathFromRoot(data, root->right, v);
    if (ifFoundInRightSubtree) {
        v.push_back(root);
        return true;
    }
    return false;
}

// helper
// Given an input root node and an integer k it prints all the nodes k level below the root
// blocker:::::: helps eliminate unwanted paths (repeated)
void printKLevelsDown(node *root, int k, node *blocker) {
    // base cases
    if (root == nullptr || k == -1 || root == blocker) {
        // if there is no tree
        return;
    }
    if (k == 0)
        // if k becomes 0 means this level needs to be printed
        cout << root->data << " ";
    // recursive cases
    printKLevelsDown(root->left, k - 1, blocker);
    printKLevelsDown(root->right, k - 1, blocker);
}

// MAIN FUNCTION
// PRINTS ALL THE NODES THAT LIE AT A DISTANCE K FROM THE TARGET NODE DATA
void printKNodesFar(node *root, int data, int k) {
    // Firstly get the path of data node
    vector<node *> path;
    pathFromRoot(data, root, path);
    // now vector v contains the path from data node to root

    // for every path element calculate and print nodes which are k-i levels down
    for (int i = 0; i < path.size() && i <= k; i++) {
        printKLevelsDown(path[i], k - i, i == 0 ? nullptr : path[i - 1]);
    }
}

int main() {
    cout << "Enter the tree" << endl;
    node *root = nullptr;
    buildTree(root);

    int targetNode;
    cout << "Enter the target node" << endl;
    cin >> targetNode;

    int k;
    cout << "Enter the levels (far from target node)" << endl;
    cin >> k;

    printKNodesFar(root, targetNode, k);

    // print entire tree
    cout << endl << endl;
    cout << "Printing entire tree:" << endl;
    bfsTraversal(root);

    return 0;
}