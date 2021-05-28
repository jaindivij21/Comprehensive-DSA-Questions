// Binary Tree
// Print the right view of the binary tree

// What i do in this problem is store the level order bfs traversal in an array of arrays and for each line/level, print the last element i.e. the right most element 

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

// main function that return an array of arrays where each array stores the level order traversal i.e. each line 
vector<vector<int>> printBfs(node *root) {
    // a vector of vectors that contain our traversal
    vector<vector<int>> v;
    // if the root/element is null, need not make any changes to our vector
    if (root == nullptr)
        return v;

    // but if the root isn't null, need to maintain a queue
    queue<node *> q;
    q.push(root);   // push that node

    // now till the queue isnt empty, pop the element, push it into the vector for that row, and finally if its childs exists, push them into the 
    while (!q.empty()) {
        int qsize = q.size();   // cal the q size for that row
        vector<int> v2;
        for (int i = 0; i < qsize; i++) {
            node *temp = q.front();
            q.pop();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
            v2.push_back(temp->data);
        }
        // this level is over
        v.push_back(v2);
    }
    return v;
}


int main() {
    node *root = nullptr;
    buildTree(root);
    vector<vector<int>> ans = printBfs(root);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i][ans[i].size() - 1] << endl;
    }

    return 0;
}