// Trees

#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int d;
    node *left;
    node *right;

    node(int data)
    {
        d = data;
        left = nullptr;
        right = nullptr;
    }
};

// build Tree Preorder
node *preorderBuild()
{
    int ele;
    cin >> ele;
    if (ele == -1)
        return nullptr;
    else
    {
        node *root = new node(ele);
        root->left = preorderBuild();
        root->right = preorderBuild();
        return root;
    }
}

// build tree Iterative
void bfsBuild(node *&root)
{
    int ele;
    cin >> ele;
    root = new node(ele);

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;
        if (l != -1)
        {
            front->left = new node(l);
            q.push(front->left);
        }
        if (r != -1)
        {
            front->right = new node(r);
            q.push(front->right);
        }
    }
}

int main()
{
    node *root = nullptr;
    root = preorderBuild();

    node *root2 = nullptr;
    bfsBuild(root2);

    return 0;
}