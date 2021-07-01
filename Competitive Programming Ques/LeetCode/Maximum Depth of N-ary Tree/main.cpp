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
    // use recursion :: DFS
    int maxDepth(Node *root)
    {
        // base case
        if (root == nullptr)
            return 0;
        // recursive cases
        int ans = 0;
        for (auto i : root->children)
        {
            ans = max(ans, maxDepth(i));
        }
        return ans + 1;
    }
};