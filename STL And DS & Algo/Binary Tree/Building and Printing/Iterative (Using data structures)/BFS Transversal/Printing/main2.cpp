// Binary Tree
// BFS TRANSVERSAL
// LEVEL ORDER TRANSVERSAL
// https://www.geeksforgeeks.org/print-level-order-traversal-line-line/
// https://www.youtube.com/watch?v=U7rLw0jXI0E

// 2.main.cpp just is different from main1.cpp such that it prints every level in different line
/*
 *  To print every level in a different line what you can do is, push nullptr into the queue whenever one level gets
 *  over. That is firstly you print the front element, push the element's children. After you have printed all the children of
 *  that level's elements, again push a nullptr to tell that, this level is over!
 */

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

// LEVEL ORDER (ITERATIVE QUEUE BASED BFS TRAVERSAL) (Different level in different lines)
void bfsTraversal(node *root) {
    // make a queue that stores address to the nodes of the binary tree
    queue<node *> q;

    // push the root node into the queue
    q.push(root);
    q.push(nullptr);

    // till the queue isn't empty, pop and print the element in front and push its children
    while (!q.empty()) {
        node *temp = q.front();

        if (temp == nullptr) {
            // if the front element is nullptr, means end of level
            cout << endl;   // print \n
            q.pop();    // pop that null
            if (!q.empty()) // and if the queue isn't empty means we need to push another null since this level's all children have already been pushed
                q.push(nullptr);
        } else {
            // if the front element isn't a nullptr

            // print that element and pop it
            cout<<temp->data<<" ";
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


