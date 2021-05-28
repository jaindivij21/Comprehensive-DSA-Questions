// Binary Tree
// Print all nodes K levels down from the root


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


void printKLevelsDown(node *root, int k) {
    // base cases
    if (root == nullptr || k == -1) {
        return;
    }
    if (k == 0)
        cout << root->data << " ";
    // recursive cases
    printKLevelsDown(root->left, k - 1);
    printKLevelsDown(root->right, k - 1);
}


int main() {
    cout << "Enter the tree" << endl;
    node *root = nullptr;
    buildTree(root);

    int k;
    cout << "Enter the target level" << endl;
    cin >> k;

    printKLevelsDown(root, k);

    // print entire tree
    cout << endl << endl;
    cout << "Printing entire tree:" << endl;
    bfsTraversal(root);

    return 0;
}