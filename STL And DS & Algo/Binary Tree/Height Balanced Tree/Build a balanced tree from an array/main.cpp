// Program to make the height balanced tree from array
/*
 * Find the mid of the tree. Make it the root. All the elements to the left of it, make up the left sub tree, while
 * right elements make the right sub tree.
 */

#include<iostream>
#include<queue>

using namespace std;

// node class
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

// print the tree
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
            cout << temp->data << " ";
            q.pop();

            // if the left child exists
            if (temp->left) {
                q.push(temp->left);
            }
            // if the right child exists
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
    return;
}

// MAIN FUNCTION
// Build using preorder (R-left-right)
node *buildHeightBalTree(int arr[], int start, int end) {
    // base case
    if (start > end) {
        return nullptr;
    }
    int mid = (start + end) / 2;
    node *root = new node(arr[mid]);
    root->left = buildHeightBalTree(arr, start, mid - 1);
    root->right = buildHeightBalTree(arr, mid + 1, end);
    return root;

}

int main() {
    // building the tree
    cout << "Enter the no. of nodes" << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the array" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // main function
    node *root = buildHeightBalTree(arr, 0, n - 1);

    // print the ans
    bfsTraversal(root);

    return 0;
}