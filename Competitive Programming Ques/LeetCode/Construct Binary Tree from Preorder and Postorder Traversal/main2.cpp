// Leetcode :: Construct Binary Tree from Preorder and Postorder Traversal
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

#include <bits/stdc++.h>

using namespace std;

// definition of a node
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// building the tree : using BFS
TreeNode *buildTree(TreeNode *&root)
{
    queue<TreeNode *> q;
    int element;
    cin >> element;
    root = new TreeNode(element);
    q.push(root);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        int left, right;
        cin >> left >> right;
        if (left != -1)
        {
            front->left = new TreeNode(left);
            q.push(front->left);
        }
        if (right != -1)
        {
            front->right = new TreeNode(right);
            q.push(front->right);
        }
    }
    return root;
}

// print the tree : using BFS
void printTree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            cout << front->val << " ";
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        cout << endl;
    }
}

int preIndex = 0, posIndex = 0;
TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
{
    TreeNode *root = new TreeNode(pre[preIndex++]);
    if (root->val != post[posIndex])
        root->left = constructFromPrePost(pre, post);
    if (root->val != post[posIndex])
        root->right = constructFromPrePost(pre, post);
    posIndex++;
    return root;
}

int main()
{
    //    TreeNode *root = nullptr;
    //    root = buildTree(root);
    //    printTree(root);

    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
    vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};

    TreeNode *ans = constructFromPrePost(preorder, postorder);
    printTree(ans);

    return 0;
}