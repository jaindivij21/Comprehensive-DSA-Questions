// Leecode : Binary Search Tree Iterator
// https://leetcode.com/problems/binary-search-tree-iterator/
// https://youtu.be/C8iHdhXjKC4

#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class BSTIterator
{
private:
    stack<TreeNode *> s; // stack to hold the nodes
public:
    // constructor
    explicit BSTIterator(TreeNode *root)
    {
        partialInorder(root);
    }

    // partial Inorder function called in the constructor : basically pushes in the stack all the left nodes until we hit null
    void partialInorder(TreeNode *root)
    {
        while (root != nullptr)
        {
            s.push(root);
            root = root->left;
        }
    }

    // method to return the next element in the inorder traversal
    int next()
    {
        TreeNode *temp = s.top();
        s.pop(); // pop the top element
        // push the right side's left children into the stack
        partialInorder(temp->right);
        // return the top's value
        return temp->val;
    }

    // function that tells if the next element even exists : can do this by checking if the stack is empty
    bool hasNext()
    {
        return !s.empty();
    }
};

int main()
{
    return 0;
}