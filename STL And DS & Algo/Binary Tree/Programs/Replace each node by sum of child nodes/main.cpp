// Program to change each node with sum of child nodes
// Bottom up approach i.e. Postorder (L-R-Root) --> basically start from the leaf nodes and make your way to the root

#include<iostream>
#include<queue>

using namespace std;

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

// preorder build
node *buildTree() {
    int element;
    cin >> element;

    if (element == -1)
        return nullptr;
    else {
        node *root = new node(element);
        root->left = buildTree();
        root->right = buildTree();
        return root;
    }
}

void printBFS(node *root) {
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
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            q.pop();
        }
    }
    cout << endl;
}

// bottom up manner
int sumReplacement(node *root) {
    //base case
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        // leaf node
        // no need to change them but just return their data
        return root->data;
    }
    // recursive part (Post order traversal (bottom up))
    int leftSubTreeSum = sumReplacement(root->left);
    int rightSubTreeSum = sumReplacement(root->right);

    // store the root data for above parent element's replacements
    int temp = root->data;
    // update the root data
    root->data = leftSubTreeSum + rightSubTreeSum;
    // return to parent
    return temp + root->data;
}

int main() {
    // building the tree
    cout << "Enter the tree (Preorder)" << endl;
    node *root = buildTree();

    printBFS(root);

    sumReplacement(root);

    printBFS(root);

    return 0;
}