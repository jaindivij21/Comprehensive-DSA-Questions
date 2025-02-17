// Leetcode: Delete Node in a BST
// https://leetcode.com/problems/delete-node-in-a-bst

#include <iostream>

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
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr) return root;

        // Find the node to be deleted and its parent
        TreeNode *parentOfSearchedNode = nullptr;
        TreeNode *searchedNode = search(root, key, parentOfSearchedNode);

        if (searchedNode == nullptr) return root;  // Key not found

        if (searchedNode->right)
        {
            // Case 1: Node has two children
            TreeNode *inorderSuccessor =
                findInorderSuccessor(searchedNode->right);
            swap(inorderSuccessor->val, searchedNode->val);
            searchedNode->right =
                deleteNode(searchedNode->right, inorderSuccessor->val);
        }
        else if (searchedNode->left)
        {
            // Case 2: Node has only left child
            TreeNode *temp = searchedNode->left;
            searchedNode->val = temp->val;
            searchedNode->left = temp->left;
            searchedNode->right = temp->right;
            delete temp;
        }
        else
        {
            // Case 3: Node has no children (leaf node)
            if (parentOfSearchedNode == nullptr)
            {  // If the node to delete is root
                delete searchedNode;
                return nullptr;
            }

            if (parentOfSearchedNode->left == searchedNode)
            {
                parentOfSearchedNode->left = nullptr;
            }
            else
            {
                parentOfSearchedNode->right = nullptr;
            }
            delete searchedNode;
        }

        return root;
    }

   private:
    TreeNode *search(TreeNode *root, int key, TreeNode *&parent)
    {
        // Base Case
        if (root == nullptr) return nullptr;

        // Recursive Cases
        if (root->val == key)
        {
            return root;
        }
        else if (root->val < key)
        {
            parent = root;
            return search(root->right, key, parent);
        }
        else
        {
            parent = root;
            return search(root->left, key, parent);
        }
    }

    TreeNode *findInorderSuccessor(TreeNode *root)
    {
        while (root->left != nullptr) root = root->left;
        return root;
    }
};

int main()
{
    BinaryTree tree;
    tree.buildFromPreorder({5, 3, 2, -1, -1, 4, -1, -1, 6, -1, -1});

    Solution solution;
    TreeNode *result = solution.deleteNode(tree.root, 3);

    return 0;
}
