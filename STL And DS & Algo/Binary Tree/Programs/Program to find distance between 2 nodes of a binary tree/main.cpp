// Binary Tree
// Program to find the distance bw 2 nodes in a tree
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

// Main function to cal the distance bw two nodes

// 2 METHODS

// 1) Find the path to root from both the nodes and then calculate the common element in both paths, thus the distance
// 2) Find lowest common ancestor for both the nodes and then add the distance from it to both the nodes

// Method 1

// helper function, calculates the path of each node from the root
bool pathFromRoot(node *root, int data, vector<int> &v) {
    // base cases
    if (root == nullptr)
        return false;
    if (root->data == data) {
        v.push_back(root->data);
        return true;
    }
    // recursive cases
    // post order traversal
    bool left = pathFromRoot(root->left, data, v);
    if (left) {
        v.push_back(root->data);
        return true;
    }
    bool right = pathFromRoot(root->right, data, v);
    if (right) {
        v.push_back(root->data);
        return true;
    }
    return false;
}

// calculates distance between the nodes
int distanceBwNodes1(int d1, int d2, node *root) {
    // both vectors store the path
    vector<int> v1;
    pathFromRoot(root, d1, v1);
    vector<int> v2;
    pathFromRoot(root, d2, v2);

    // ans stores our answer
    int ans = 0;
    int i = v1.size() - 1;
    int j = v2.size() - 1;

    // run a loop from the end until we find a non common element

    while (i >= 0 && j >= 0 && v1[i] == v2[j]) {
        i--;
        j--;
    }
    // we get the last common node in the path of both the nodes
    i++;
    j++;

    ans = i + j;    // i and j are distance from common ancestor

    return ans;
}

// Method 2

// helper function1: finding the lca
node *lca(node *root, int a, int b) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->data == a || root->data == b)
        return root;

    // search in left and right subtrees for the ancestor
    node *leftAns = lca(root->left, a, b);
    node *rightAns = lca(root->right, a, b);

    if (leftAns != nullptr && rightAns != nullptr) {
        return root;
    }
    if (leftAns != nullptr)
        return leftAns;
    return rightAns;
}

// helper function2: finds/search a node and return its level
int levelOfaNode(node *root, int key, int level) {
    // base cases
    if (root == nullptr)
        return -1;
    if (root->data == key)
        return level;
    // recursive cases
    int left = levelOfaNode(root->left, key, level + 1);
    if (left != -1) {
        // if node found in left subtree return the level
        return left;
    }
    // else must have been found in the right subtree
    return levelOfaNode(root->right, key, level + 1);
}

// cal distance bw the nodes
int distanceBwNodes2(int a, int b, node *root) {
    node *lcaNode = lca(root, a, b);
    int l1 = levelOfaNode(lcaNode, a, 0);
    int l2 = levelOfaNode(lcaNode, b, 0);
    return l1 + l2;
}

// main function
int main() {
    node *root = nullptr;
    cin >> root;
    cout << root;

    // main program
    cout << "Enter the data of the 2 nodes for which the distance is to be found" << endl;
    int a, b;
    cin >> a >> b;
    cout << "The distance bw nodes in the binary tree is (Method 1): " << distanceBwNodes1(a, b, root) << endl;
    cout << "The distance bw nodes in the binary tree is (Method 2): " << distanceBwNodes2(a, b, root) << endl;

    return 0;
}