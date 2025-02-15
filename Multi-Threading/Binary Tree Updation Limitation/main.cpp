#include <iostream>
#include <thread>
#include <mutex>

// Class representing a node in the binary tree
class TreeNode
{
public:
  int value;       // Value of the node
  TreeNode *left;  // Pointer to the left child
  TreeNode *right; // Pointer to the right child
  std::mutex mtx;  // Mutex to synchronize access to this node

  explicit TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Binary tree class with thread-safe update operations
class BinaryTree
{
private:
  // Recursively locks an entire subtree
  void lockSubtree(TreeNode *node)
  {
    if (!node)
      return;

    node->mtx.lock(); // Lock this node, blocking if another thread has already locked it

    // Recursively lock left and right subtrees
    lockSubtree(node->left);
    lockSubtree(node->right);
  }

  // Recursively unlocks an entire subtree in reverse order (postorder traversal)
  void unlockSubtree(TreeNode *node)
  {
    if (!node)
      return;

    // Recursively unlock left and right subtrees first
    unlockSubtree(node->left);
    unlockSubtree(node->right);

    node->mtx.unlock(); // Unlock this node
  }

public:
  TreeNode *root; // Pointer to the root of the binary tree

  // Constructor to initialize the tree with a root node
  explicit BinaryTree(int rootValue)
  {
    root = new TreeNode(rootValue);
  }

  // Inserts a node as a left or right child of the given parent node
  void insert(TreeNode *parent, int value, bool isLeft)
  {
    if (isLeft && !parent->left) // If left child is empty, insert the new node
    {
      parent->left = new TreeNode(value);
    }
    else if (!isLeft && !parent->right) // If right child is empty, insert the new node
    {
      parent->right = new TreeNode(value);
    }
  }

  // Updates the value of a node safely using thread synchronization
  void updateNode(TreeNode *node, int newValue)
  {
    lockSubtree(node); // Lock the node and its entire subtree to ensure exclusive access

    std::cout << "Updating node " << node->value << " to " << newValue << std::endl;
    node->value = newValue;                               // Update the node's value
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate some processing delay
    std::cout << "Update complete for node " << newValue << std::endl;

    unlockSubtree(node); // Unlock the node and its subtree after updating
  }
};

// Function to be executed by threads, updating a specific node's value
void threadFunc(BinaryTree &tree, TreeNode *node, int newValue)
{
  tree.updateNode(node, newValue);
}

int main()
{
  // Create a binary tree with root node value 10
  BinaryTree tree(10);

  // Insert nodes into the tree
  tree.insert(tree.root, 5, true);        // Insert 5 as left child of root (10)
  tree.insert(tree.root, 20, false);      // Insert 20 as right child of root (10)
  tree.insert(tree.root->left, 3, true);  // Insert 3 as left child of node 5
  tree.insert(tree.root->left, 7, false); // Insert 7 as right child of node 5

  // Start multiple threads to update different nodes concurrently
  std::thread t1(threadFunc, std::ref(tree), tree.root->left, 50);       // Update node 5 to 50
  std::thread t2(threadFunc, std::ref(tree), tree.root->left->left, 30); // Update node 3 to 30
  std::thread t3(threadFunc, std::ref(tree), tree.root->right, 40);      // Update node 20 to 40

  // Wait for all threads to complete execution
  t1.join();
  t2.join();
  t3.join();

  return 0;
}
