// Program: Creation of Binary Tree using Recursive (Preorder/DFS) and Iterative (LevelOrder/BFS) Traversal Vectors

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TreeNode class representing a node in the binary tree
class TreeNode
{
public:
  int value;
  TreeNode *left;
  TreeNode *right;

  // Constructor to initialize a tree node
  explicit TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
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
   * Builds a binary tree from a given level-order traversal.
   * -1 represents a null node.
   */
  void buildFromLevelOrder(const vector<int> &levelOrderValues)
  {
    if (levelOrderValues.empty() || levelOrderValues[0] == -1)
    {
      root = nullptr;
      return;
    }

    int index = 0;
    root = new TreeNode(levelOrderValues[index++]);

    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty() && index < levelOrderValues.size())
    {
      TreeNode *currentNode = nodeQueue.front();
      nodeQueue.pop();

      // Process left child
      if (index < levelOrderValues.size() && levelOrderValues[index] != -1)
      {
        currentNode->left = new TreeNode(levelOrderValues[index]);
        nodeQueue.push(currentNode->left);
      }
      index++;

      // Process right child
      if (index < levelOrderValues.size() && levelOrderValues[index] != -1)
      {
        currentNode->right = new TreeNode(levelOrderValues[index]);
        nodeQueue.push(currentNode->right);
      }
      index++;
    }
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

// Main function to demonstrate tree construction
int main()
{
  // Preorder-based tree construction
  vector<int> preorderValues = {8, 5, 1, -1, -1, 7, -1, -1, 10, -1, 12, -1, -1};
  BinaryTree treeFromPreorder;
  treeFromPreorder.buildFromPreorder(preorderValues);

  // Level-order-based tree construction
  vector<int> levelOrderValues = {8, 5, 10, 1, 7, 12, -1, -1, -1, -1, -1, -1, -1};
  BinaryTree treeFromLevelOrder;
  treeFromLevelOrder.buildFromLevelOrder(levelOrderValues);

  cout << "Binary trees constructed successfully!" << endl;
  return 0;
}
