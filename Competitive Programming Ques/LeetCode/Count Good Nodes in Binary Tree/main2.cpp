// Leetcode: Count Good Nodes in Binary Tree
// https://leetcode.com/problems/count-good-nodes-in-binary-tree

#include <iostream>
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
  ~BinaryTree()
  {
    deleteTree(root);
  }

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
  TreeNode *constructTreeFromPreorder(const vector<int> &preorderValues, int &index)
  {
    if (index >= preorderValues.size() || preorderValues[index] == -1)
    {
      index++; // Move to the next element
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
    if (node == nullptr)
      return;

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
  int goodNodes(TreeNode *root)
  {
    int ans = 1;
    int l = 0, r = 0;

    if (root != nullptr)
    {
      int maxEle = root->val;

      if (root->left)
        l = dfs(root->left, maxEle);
      if (root->right)
        r = dfs(root->right, maxEle);

      return ans + l + r;
    }
    else
    {
      return 0;
    }
  }

private:
  int dfs(TreeNode *root, int maxEle)
  {
    // Base Case
    if (root == nullptr)
      return 0;

    // Recursive Case
    int ans = 0;
    if (root->val >= maxEle)
    {
      maxEle = root->val;
      ans++;
    }

    int l = dfs(root->left, maxEle);
    int r = dfs(root->right, maxEle);
    return ans + l + r;
  }
};

// Main function to demonstrate tree construction
int main()
{
  // Preorder-based tree construction
  vector<int> preorderValues = {3, 1, -1, -1, 2, 4, -1, -1, 5, -1, -1};
  BinaryTree treeFromPreorder;
  treeFromPreorder.buildFromPreorder(preorderValues);

  Solution solution;
  cout << "Max Depth: " << solution.goodNodes(treeFromPreorder.root) << endl;

  return 0;
}
