// Leetcode: Create Binary Tree From Descriptions
// https://leetcode.com/problems/create-binary-tree-from-descriptions

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

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

// Helper function to initialize tree data and find the root node
void initTreeData(vector<vector<int>> &descriptions, unordered_map<int, pair<int, int>> &nodes, int &rootValue)
{
  unordered_set<int> possibleRootNodes;

  // Step 1: Build the nodes map and track possible root nodes
  for (const auto &desc : descriptions)
  {
    possibleRootNodes.insert(desc[0]);

    int parent = desc[0];
    int child = desc[1];
    bool isLeftChild = desc[2] == 1;

    // If the parent node is not in the map, initialize its children
    int leftChild, rightChild;
    if (nodes.find(parent) == nodes.end())
    {
      leftChild = isLeftChild ? child : -1;
      rightChild = isLeftChild ? -1 : child;
    }
    else
    {
      leftChild = isLeftChild ? child : nodes[parent].first;
      rightChild = isLeftChild ? nodes[parent].second : child;
    }
    nodes[parent] = make_pair(leftChild, rightChild);
  }

  // Step 2: Remove non-root nodes from possible root nodes set
  for (const auto &desc : descriptions)
  {
    possibleRootNodes.erase(desc[1]);
  }

  // Step 3: The remaining node in possibleRootNodes is the root
  rootValue = *possibleRootNodes.begin();
}

// Recursive helper function to build the binary tree
TreeNode *buildTree(int currentNodeValue, unordered_map<int, pair<int, int>> &nodes)
{
  // Base case: if the node value is -1, return null
  if (currentNodeValue == -1)
  {
    return nullptr;
  }

  // Create a new TreeNode
  auto *root = new TreeNode(currentNodeValue);

  // Get the left and right children from the nodes map
  int leftChild = -1, rightChild = -1;
  if (nodes.find(currentNodeValue) != nodes.end())
  {
    leftChild = nodes[currentNodeValue].first;
    rightChild = nodes[currentNodeValue].second;
  }

  // Recursively build the left and right subtrees
  root->left = buildTree(leftChild, nodes);
  root->right = buildTree(rightChild, nodes);

  return root;
}

// Main function to create the binary tree from descriptions
TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
{
  unordered_map<int, pair<int, int>> nodes;
  int rootValue;

  // Initialize tree data and find the root value
  initTreeData(descriptions, nodes, rootValue);

  // Build the tree starting from the root value
  TreeNode *root = buildTree(rootValue, nodes);

  return root;
}

int main()
{
  vector<vector<int>> descriptions = {{20, 15, 1},
                                      {20, 17, 0},
                                      {50, 20, 1},
                                      {50, 80, 0},
                                      {80, 19, 1}};

  TreeNode *ans = createBinaryTree(descriptions);
  delete (ans);
  return 0;
}