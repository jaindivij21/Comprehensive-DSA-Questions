// Leetcode: Kth Largest Sum in a Binary Tree
// https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// TreeNode Structure for Binary Tree
class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @brief Calculates the kth largest level sum in a binary tree.
 *
 * @param root The root of the binary tree.
 * @param k The kth level sum to find.
 * @return long long The kth largest level sum. Returns -1 if there are fewer than k levels.
 */
long long kthLargestLevelSum(TreeNode *root, int k)
{
  // Priority queue to store level sums in descending order
  priority_queue<long long> maxHeap;

  // Level Order Traversal using a queue
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int levelSize = q.size();
    long long levelSum = 0;

    // Calculate sum for current level
    for (int i = 0; i < levelSize; i++)
    {
      TreeNode *current = q.front();
      q.pop();

      // Add node value to current level sum
      levelSum += current->val;

      // Add child nodes to the queue for next level processing
      if (current->left != nullptr)
        q.push(current->left);
      if (current->right != nullptr)
        q.push(current->right);
    }

    // Store the sum of the current level in the max heap
    maxHeap.push(levelSum);
  }

  long long result = -1;
  // Extract the kth largest level sum from the max heap
  while (k > 0 && !maxHeap.empty())
  {
    result = maxHeap.top();
    maxHeap.pop();
    k--;
  }

  return k == 0 ? result : -1; // Return -1 if fewer than k levels
}

/**
 * @brief Builds a binary tree from a vector representation (level order).
 *
 * @param root Reference to the root pointer.
 * @param nums Vector representing the level order traversal of the binary tree.
 * @return TreeNode* The root of the constructed binary tree.
 */
TreeNode *buildLevelOrderBinaryTree(TreeNode *&root, vector<int> &nums)
{
  if (nums.empty())
    return nullptr;

  queue<TreeNode *> q;
  int index = 0;
  root = new TreeNode(nums[index++]);
  q.push(root);

  while (!q.empty())
  {
    TreeNode *current = q.front();
    q.pop();

    if (index < nums.size() && nums[index] != -1)
    {
      current->left = new TreeNode(nums[index]);
      q.push(current->left);
    }
    index++;

    if (index < nums.size() && nums[index] != -1)
    {
      current->right = new TreeNode(nums[index]);
      q.push(current->right);
    }
    index++;
  }

  return root;
}

int main()
{
  // Example usage
  vector<int> nums = {5, 8, 9, 2, 1, 3, 7, -1, -1, -1, -1, -1, -1, -1, -1};
  TreeNode *root = nullptr;
  root = buildLevelOrderBinaryTree(root, nums);

  int k = 2;
  cout << "Kth largest level sum: " << kthLargestLevelSum(root, k) << endl;

  return 0;
}
