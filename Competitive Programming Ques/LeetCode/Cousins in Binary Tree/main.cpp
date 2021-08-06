// Leetcode : Cousins in Binary Tree
// https://leetcode.com/problems/cousins-in-binary-tree/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(TreeNode *root) {
    int ele;
    cin >> ele;

    if (ele == -1)
        return nullptr;
    else {
        auto *temp = new TreeNode(ele);
        temp->left = buildTree(temp->left);
        temp->right = buildTree(temp->right);
        return temp;
    }
}

// BFS : Level Order Traversal using a queue
bool bfs(TreeNode *root, int x, int y) {
    // Make a queue that stores nodes
    queue<TreeNode *> q;

    // handle the base case i.e. if you find any value in the root itself; since we have only one root, cousins aren't possible
    if (root->val == x || root->val == y)
        return false;

    // push the root
    q.push(root);

    // while the queue isn't empty calculate the number of nodes at that level
    // make a flag that tells us if x and y occur at that level or not
    while (!q.empty()) {
        int size = q.size();
        bool flag = false;
        // for all the nodes at that level, pop them one by one and push their children into the queue, while also calculating if the x,y exist as cousins or not
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();
            // for each node
            // push the left child if it exists
            if(front->left){
                if(flag){
                    // if the flag is true: means we already have encountered either x or y at this same level but for other parent;
                    // so if you find the other one, just return true
                    if(front->left->val == x || front->left->val == y)
                        return true;
                }
                // push the child
                q.push(front->left);
                // if this node's left child is eql to any one of our values make the flag true, and continue onto the next iteration : which essentially means MOVE ONTO THE
                // NEXT PARENT (since cousins)
                if(front->left->val == x || front->left->val == y){
                    flag = true;
                    continue;
                }
            }
            // push the right child if it exists
            if(front->right){
                if(flag){
                    if(front->right->val == x || front->right->val == y)
                        return true;
                }
                // push the child
                q.push(front->right);
                if(front->right->val == x || front->right->val == y){
                    flag = true;
                    continue;
                }
            }
        }
    }
    // return false if x and y aren't cousins
    return false;
}

bool isCousins(TreeNode *root, int x, int y) {
    return bfs(root, x, y);
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);

    int x, y;
    cin >> x >> y;
    cout << isCousins(root, x, y);

    return 0;
}