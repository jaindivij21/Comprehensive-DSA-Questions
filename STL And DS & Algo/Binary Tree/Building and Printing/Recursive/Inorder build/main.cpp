// Binary Tree
// Inorder build
// Using recursion

/*
 * For inorder building of a binary tree, we need the pre order transversal also along with the inorder transversal
 * due to the fact, we need the root element. The root element can be identified using the first element of preorder which
 * otherwise cannot be identified. (For this to work there must not be duplicates in the tree)
 */

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

// function to make the tree using inorder
node *createTreeFromTrav(int *in, int *pre, int s, int e) {
    // IMPORTANT
    static int i = 0;   // make a static variable that stores the current root from preorder (making it static so that it doesnt backtrack during recursion)

    // Base Case
    if (s > e) {
        return nullptr;
    }
    // Recursive Case
    node *root = new node(pre[i]);

    // search this index's data in the inorder cuz that'll be the root and to the left of it elements will be left sub tree and to the right elements will be right sub tree
    int index = -1;
    // make a loop to find the root in inorder array
    for (int j = s; s <= e; j++) {
        if (in[j] == pre[i]) {
            index = j;
            break;
        }
    }

    // update the index i.e. preorder array pointer
    i++;
    // main recursive cases to make the left and right sub trees
    root->left = createTreeFromTrav(in, pre, s, index - 1);
    root->right = createTreeFromTrav(in, pre, index + 1, e);
    return root;
}

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
    // input the arrays
    cout << "Enter the number of elements in the tree" << endl;
    int n;
    cin >> n;
    cout << "Enter the preorder transversal" << endl;
    int preorder[n];
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    cout << "Enter the inorder transversal" << endl;
    int inorder[n];
    for (int i = 0; i < n; i++)
        cin >> inorder[i];

    node *root = createTreeFromTrav(inorder, preorder, 0, n - 1);

    printBfs(root);

    return 0;
}