// Binary Tree
// BFS TRANSVERSAL
// LEVEL ORDER TRANSVERSAL

#include<iostream>
#include<queue>

using namespace std;


// node that'll help us make the tree
class node {
public:
    int data;
    node *rightChild;
    node *leftChild;

    node(int d) {
        data = d;
        rightChild = nullptr;
        leftChild = nullptr;
    }
};

// PREORDER build tree function
node *buildTree() {
    int element;
    cin >> element;

    // base case (if user types -1, means stop the tree there)
    if (element == -1)
        return nullptr;
    else {
        node *root = new node(element);
        root->leftChild = buildTree();
        root->rightChild = buildTree();
        return root;
    }
}

// LEVEL ORDER (ITERATIVE QUEUE BASED BFS TRAVERSAL
void bfsTraversal(node *root) {
    // make a queue that stores address to the nodes of the binary tree
    queue<node *> q;

    // push the root node into the queue
    q.push(root);

    // till the queue isn't empty, pop and print the element in front and push its children
    while (!q.empty()) {
        node *temp = q.front();
        cout << temp->data << " ";
        q.pop();

        // if the left child exists
        if (temp->leftChild) {
            q.push(temp->leftChild);
        }
        // if the right child exists
        if (temp->rightChild) {
            q.push(temp->rightChild);
        }
    }
    return;
}

int main() {
    cout << "Enter the tree" << endl;
    node *root = buildTree();
    cout << "\nLEVEL ORDER (BFS) TRAVERSAL:" << endl;
    bfsTraversal(root);
    return 0;
}


