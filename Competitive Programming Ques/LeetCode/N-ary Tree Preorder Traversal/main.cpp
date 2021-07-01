#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    void helper(Node *root, vector<int> &ans)
    {
        // base case : nil
        if (root == nullptr)
            return;
        // recursive case
        ans.push_back(root->val);
        for (auto i : root->children)
        {
            helper(i, ans);
        }
    }

    // use recursion :: DFS
    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};