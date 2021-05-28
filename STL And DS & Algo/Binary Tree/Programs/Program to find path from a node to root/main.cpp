// Binary Tree
//

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

// finding a node
bool findandPathfromRoot(int data, node *root, vector<int> &v) {
    // base case
    if (root == nullptr)
        return false;
    if (root->data == data) {
        v.push_back(root->data);
        return true;
    }

    // recursive cases
    bool ifFoundInLeftSubtree = findandPathfromRoot(data, root->left, v);
    if (ifFoundInLeftSubtree) {
        v.push_back(root->data);
        return true;
    }
    bool ifFoundInRightSubtree = findandPathfromRoot(data, root->right, v);
    if (ifFoundInRightSubtree) {
        v.push_back(root->data);
        return true;
    }

    return false;
}

int main() {
    cout << "Enter the tree" << endl;
    node *root = nullptr;
    buildTree(root);

    cout << "Enter the node to find" << endl;
    int data;
    cin >> data;

    vector<int> v;
    bool ans = findandPathfromRoot(data, root, v);

    // print results
    if (ans)
        cout << "Yes, The node was found" << endl;
    else
        cout << "No, The node wasn't found" << endl;

    cout << "The path from that node to root is:" << endl;
    for (auto itr: v) {
        cout << itr << " ";
    }

    cout << endl << endl;
    // print entire tree
    bfsTraversal(root);

    return 0;
}