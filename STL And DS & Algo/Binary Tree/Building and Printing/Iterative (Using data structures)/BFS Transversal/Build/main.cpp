// Binary Tree
// Print the right view of the tree

#include<iostream>
#include<queue>

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

// level order tree build
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

// bfs level wise printing
void printBfs(node *root) {
    queue<node *> q;
    q.push(root);
    q.push(nullptr);
    while (!q.empty()) {
        node *temp = q.front();
        if (temp == nullptr) {
            cout << endl;
            q.pop();
            if (!q.empty()) {
                q.push(nullptr);
            }
        } else {
            cout << temp->data << " ";
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main() {
    node *root = nullptr;
    buildTree(root);
    printBfs(root);
    return 0;
}