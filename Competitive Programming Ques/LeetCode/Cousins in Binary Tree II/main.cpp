// Leetcode: Cousins in Binary Tree II
// https://leetcode.com/problems/cousins-in-binary-tree-ii

#include <queue>
#include <unordered_map>

using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  TreeNode *replaceValueInTree(TreeNode *root)
  {
    if (root == nullptr)
      return nullptr;

    unordered_map<int, int> levelSums = calculateLevelSums(root);
    replaceNodeValues(root, levelSums);

    return root;
  }

private:
  // Helper function to calculate the sum of node values at each level
  unordered_map<int, int> calculateLevelSums(TreeNode *root)
  {
    unordered_map<int, int> levelSums;
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int currentLevel = 0;

    while (!nodeQueue.empty())
    {
      int levelSize = nodeQueue.size();
      int currentLevelSum = 0;

      for (int i = 0; i < levelSize; i++)
      {
        TreeNode *currentNode = nodeQueue.front();
        nodeQueue.pop();
        currentLevelSum += currentNode->val;

        if (currentNode->left)
          nodeQueue.push(currentNode->left);
        if (currentNode->right)
          nodeQueue.push(currentNode->right);
      }

      levelSums[currentLevel] = currentLevelSum;
      currentLevel++;
    }

    return levelSums;
  }

  // Helper function to replace node values in the tree
  void replaceNodeValues(TreeNode *root, const unordered_map<int, int> &levelSums)
  {
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);
    int currentLevel = 0;

    while (!nodeQueue.empty())
    {
      int levelSize = nodeQueue.size();

      for (int i = 0; i < levelSize; i++)
      {
        TreeNode *currentNode = nodeQueue.front();
        nodeQueue.pop();

        // Root node should always have a value of 0
        if (currentLevel == 0)
        {
          currentNode->val = 0;
        }

        // Calculate the sum of current node's children
        int childrenSum = 0;
        if (currentNode->left)
          childrenSum += currentNode->left->val;
        if (currentNode->right)
          childrenSum += currentNode->right->val;

        // Replace the left and right child values with the adjusted level sum
        if (currentNode->left)
        {
          currentNode->left->val = levelSums.at(currentLevel + 1) - childrenSum;
          nodeQueue.push(currentNode->left);
        }
        if (currentNode->right)
        {
          currentNode->right->val = levelSums.at(currentLevel + 1) - childrenSum;
          nodeQueue.push(currentNode->right);
        }
      }

      currentLevel++;
    }
  }
};

int main()
{
  Solution sol;
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right->right = new TreeNode(5);
  sol.replaceValueInTree(root);

  return 0;
}