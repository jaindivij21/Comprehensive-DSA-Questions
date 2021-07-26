// Leetcode :: N-ary Tree Level Order Traversal
// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

// N-ary problem : means any node can have multiple children

#include <bits/stdc++.h>

using namespace std;

// Node defination
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

void bfs(Node *root, vector<vector<int>> &ans)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> temp;
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();
            
            // Corner Case Handle**
            if (front != nullptr)
            {
                temp.push_back(front->val);
                // push all the children of the node
                for (auto i : front->children)
                {
                    q.push(i);
                }
            }
        }
        // Corner Case Handle**
        if(!temp.empty())
            ans.push_back(temp);
    }
}

vector<vector<int>> levelOrder(Node *root)
{
    vector<vector<int>> ans;
    bfs(root, ans);
    return ans;
}

int main()
{
    return 0;
}