// Evaluate Boolean Binary Tree
// https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TreeNode
{
public:
  int val;
  TreeNode *left;
  TreeNode *right;

  // Default constructor
  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  // Constructor with value
  explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  // Constructor with value and children
  TreeNode(int x, TreeNode *leftChild, TreeNode *rightChild) : val(x), left(leftChild), right(rightChild) {}

  // Methods
  static TreeNode *createTree(vector<int> &nums)
  {
    if (nums.empty() || nums[0] == -1)
    {
      return nullptr;
    }

    auto *root = new TreeNode(nums[0]);
    queue<TreeNode *> q;
    q.push(root);
    int index = 1;

    while (index < nums.size())
    {
      TreeNode *top = q.front();
      q.pop();

      // Left Child
      if (index < nums.size() && nums[index] != -1)
      {
        top->left = new TreeNode(nums[index]);
        q.push(top->left);
      }
      index++;

      // Right Child
      if (index < nums.size() && nums[index] != -1)
      {
        top->right = new TreeNode(nums[index]);
        q.push(top->right);
      }
      index++;
    }

    return root;
  }

  static void levelOrderPrint(TreeNode *root)
  {
    if (!root)
    {
      return;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      for (int i = 0; i < q.size(); i++)
      {
        TreeNode *front = q.front();
        q.pop();

        cout << front->val << " ";

        if (front->left != nullptr)
        {
          q.push(front->left);
        }
        if (front->right != nullptr)
        {
          q.push(front->right);
        }
      }

      cout << endl;
    }
  }
};

// Recursive approach to pass the boolean result up from the bottom in a bottoms-up approach
bool evaluateTree(TreeNode *root)
{
  // Base Case: if root is a leaf node
  if (root->left == nullptr && root->right == nullptr)
  {
    return root->val; // Return the value (0 or 1)
  }

  // Recursive Cases
  int left = evaluateTree(root->left);
  int right = evaluateTree(root->right);

  // Evaluate the current node based on its value (2 for OR, 3 for AND)
  return root->val == 2 ? left || right : left && right;
}

int main()
{
  int n;
  cin >> n;
  vector<int> nums(n);

  // Take Input for vector
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  TreeNode *root = TreeNode::createTree(nums);

  cout << evaluateTree(root) << endl;

  return 0;
}