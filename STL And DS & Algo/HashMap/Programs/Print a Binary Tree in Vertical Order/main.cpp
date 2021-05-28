 // Print the vertical order of the binary tree
// We solve this using hashmap as we'll store corresponding distance from root towards left or right as the key and it's value as vector or array of integers that lie on that distance

#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<queue>

using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;

    node(int d) {
        left = nullptr;
        right = nullptr;
        data = d;
    }
};

// 1 2 4 -1 -1 5 -1 8 -1 -1 3 6 -1 -1 7 -1 9 -1 -1
node *buildTree() {
    int element;
    cin >> element;
    if (element == -1) {
        return nullptr;
    } else {
        node *temp = new node(element);
        temp->left = buildTree();
        temp->right = buildTree();
        return temp;
    }
}

// pass the distance from the root which by default is 0
void makeMap(node *root, map<int, vector<int>> &tree, int d = 0) {
    // traverse the tree and add elements to the map
    if (root == nullptr) {
        return;
    } else {
        // pre-order
        tree[d].push_back(root->data);
        makeMap(root->left, tree, d - 1);
        makeMap(root->right, tree, d + 1);
    }
}

void printVerticalTree(node *root) {
    // make a map that stores distance from root and vector of elements
    map<int, vector<int>> tree;
    makeMap(root, tree);

    // we have the map ready as we have travelled the entire tree
    // find the minimum key :: would have to iterate the entire hash map keys, therefore better used a map instead of unordered map
    for (auto itr: tree) {
        cout << itr.first << ": ";
        // time to print the vector
        for (auto itr2 : itr.second) {
            cout << itr2 << " ";
        }
        cout << endl;
    }

}

int main() {
    node *root = buildTree();
    printVerticalTree(root);

    return 0;
}