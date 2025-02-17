// Leetcode: Binary Tree Right Side View
// https://leetcode.com/problems/binary-tree-right-side-view

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TreeNode class representing a node in the binary tree
class TreeNode
{
   public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructor to initialize a tree node
    explicit TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// BinaryTree class representing a binary tree
class BinaryTree
{
   public:
    TreeNode *root;

    // Constructor initializing root to nullptr
    BinaryTree() : root(nullptr) {}

    // Destructor to deallocate all nodes and prevent memory leaks
    ~BinaryTree() { deleteTree(root); }

    /**
     * Builds a binary tree from a given preorder traversal.
     * -1 represents a null node.
     */
    void buildFromPreorder(const vector<int> &preorderValues)
    {
        int index = 0;
        root = constructTreeFromPreorder(preorderValues, index);
    }

   private:
    /**
     * Recursively constructs a binary tree from a preorder sequence.
     * @param preorderValues The preorder traversal values.
     * @param index The current index in the traversal.
     * @return Pointer to the constructed subtree.
     */
    TreeNode *constructTreeFromPreorder(const vector<int> &preorderValues,
                                        int &index)
    {
        if (index >= preorderValues.size() || preorderValues[index] == -1)
        {
            index++;  // Move to the next element
            return nullptr;
        }

        TreeNode *node = new TreeNode(preorderValues[index++]);

        // Recursively construct the left and right subtrees
        node->left = constructTreeFromPreorder(preorderValues, index);
        node->right = constructTreeFromPreorder(preorderValues, index);

        return node;
    }

    /**
     * Recursively deletes all nodes in the binary tree to prevent memory leaks.
     * @param node The current node to delete.
     */
    void deleteTree(TreeNode *node)
    {
        if (node == nullptr) return;

        // Recursively delete left and right subtrees
        deleteTree(node->left);
        deleteTree(node->right);

        // Delete the current node
        delete node;
    }
};

class Solution
{
   public:
    // Function to return the rightmost node values from each level in the
    // binary tree
    vector<int> rightSideView(TreeNode *root)
    {
        if (root == nullptr) return {};  // Handle empty tree case

        vector<int> rightSideValues;
        queue<TreeNode *> nodeQueue;

        nodeQueue.push(root);

        // Process each level in the tree
        while (!nodeQueue.empty())
        {
            int levelSize =
                nodeQueue.size();  // Number of nodes at the current level

            // Traverse all nodes at the current level
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *currentNode = nodeQueue.front();
                nodeQueue.pop();

                // If this is the last node in the current level, add its value
                // to the result
                if (i == levelSize - 1)
                {
                    rightSideValues.push_back(currentNode->val);
                }

                // Enqueue left and right children if they exist
                if (currentNode->left)
                {
                    nodeQueue.push(currentNode->left);
                }
                if (currentNode->right)
                {
                    nodeQueue.push(currentNode->right);
                }
            }
        }

        // Return the rightmost node values for each level
        return rightSideValues;
    }
};

int main()
{
    // Preorder-based tree construction
    vector<int> preorderValues = {1, 2, 3, -1, 5, -1, -1, 4, -1, -1, -1};
    BinaryTree treeFromPreorder;
    treeFromPreorder.buildFromPreorder(preorderValues);

    Solution solution;
    cout << solution.rightSideView(treeFromPreorder.root)
         << endl;  // Output: [1, 3, 4]

    return 0;
}
