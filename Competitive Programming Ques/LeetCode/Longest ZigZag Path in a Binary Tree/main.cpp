// Leetcode: Longest ZigZag Path in a Binary Tree
// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

#include <iostream>
#include <vector>

using namespace std;

class TreeNode
{
   public:
    int val;
    TreeNode *left;
    TreeNode *right;

    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree
{
   public:
    TreeNode *root;

    Tree() { root = nullptr; }

    TreeNode *create(vector<int> &nodes, int &index)
    {
        // Base Case
        if (index >= nodes.size() || nodes[index] == -1)
        {
            index++;
            return nullptr;
        }

        // Recursive Cases
        auto *node = new TreeNode(nodes[index]);
        index++;
        node->left = create(nodes, index);
        node->right = create(nodes, index);

        return node;
    }
};

class Solution
{
   public:
    int longestZigZag(TreeNode *root)
    {
        // Base case: If the tree is empty, return 0
        if (!root) return 0;

        // Recursive Cases: To keep track of the maximum ZigZag path length
        int maxLength = 0;

        // Start DFS from the root's left and right children
        dfs(root->left, true, 1, maxLength);
        dfs(root->right, false, 1, maxLength);

        return maxLength;
    }

   private:
    /**
     * Helper function to traverse the tree in a DFS manner while tracking the
     * longest ZigZag path.
     * @param node - The current node in traversal.
     * @param cameFromLeft - Indicates if the current path came from a left
     * child (true) or right child (false).
     * @param pathLength - The length of the current ZigZag path.
     * @param maxLength - Reference to the variable tracking the longest ZigZag
     * path found.
     */
    void dfs(TreeNode *node, bool cameFromLeft, int pathLength, int &maxLength)
    {
        if (node == nullptr)
        {
            maxLength = max(maxLength, pathLength - 1);
            return;
        }

        if (cameFromLeft)
        {
            // If we came from the left, we continue to the left with a reset
            // path (1) and to the right with an incremented path length
            dfs(node->left, true, 1, maxLength);
            dfs(node->right, false, pathLength + 1, maxLength);
        }
        else
        {
            // If we came from the right, we continue to the right with a reset
            // path (1) and to the left with an incremented path length
            dfs(node->left, true, pathLength + 1, maxLength);
            dfs(node->right, false, 1, maxLength);
        }
    }
};

int main()
{
    vector<int> nodes = {1, -1, 1, 1,  1,  -1, -1, -1,
                         1, -1, 1, -1, -1, 1,  -1, -1};
    Tree tree;

    int rootNode = 0;
    tree.root = tree.create(nodes, rootNode);

    Solution solution;
    cout << solution.longestZigZag(tree.root) << endl;

    return 0;
}