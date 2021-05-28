// Binary Tree
// Level Wise (BFS)

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
    printTree(root);
    return os;
}

istream &operator>>(istream &is, node *&root) {
    // build tree level wise
    buildTree(root);
    return is;
}

// main function
int main() {
    node *root = nullptr;
    cin >> root;
    cout << root;

    return 0;
}