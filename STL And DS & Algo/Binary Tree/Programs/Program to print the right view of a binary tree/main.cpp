// Binary Tree
// Print the right view of the binary tree

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

// build Tree level order
void buildTree(node *&root) {
    // input the root node
    int element;
    cin >> element;
    // make the queue
    queue<node *> q;

    // make the root node and push it into the queue
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

// print the right view of the binary tree
// will follow top down level wise bfs approach
vector<int> rightView(node *root) {
    vector<int> v;
    // if the tree is empty, no right view, return empty vector
    if (root == nullptr)
        return v;

    // if there is a tree
    queue<node *> q;
    // push the root into the queue and the vector
    q.push(root);

    // while the queue isn't empty
    while (!q.empty()) {
        int qsize = q.size();
        for (int i = 0; i < qsize; i++) {
            node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            if (i == qsize - 1)
                // push in the vector only if i is equal to the size of the queue which means we are on the last element of that level
                v.push_back(temp->data);
        }
    }
    return v;
}

int main() {
    node *root = nullptr;
    buildTree(root);
    vector<int> ans = rightView(root);
    for (auto i: ans)
        cout << i << endl;
    return 0;
}