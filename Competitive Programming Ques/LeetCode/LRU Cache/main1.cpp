#include <iostream>
#include <unordered_map>

using namespace std;

// Node structure for the doubly linked list
class Node
{
public:
  int key, value;
  Node *prev, *next;

  Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

// LRU Cache implementation using Hash Map and Doubly Linked List
class LRUCache
{
private:
  int capacity;
  unordered_map<int, Node *> cache; // Maps key to node in the linked list
  Node *head, *tail;                // Head and tail pointers

  // Move a node to the head (most recently used)
  void moveToHead(Node *node)
  {
    removeNode(node);
    addToHead(node);
  }

  // Remove a node from the doubly linked list
  static void removeNode(Node *node)
  {
    if (node->prev)
      node->prev->next = node->next;
    if (node->next)
      node->next->prev = node->prev;
  }

  // Add a node right after the head
  void addToHead(Node *node)
  {
    if (!head)
    {
      head = tail = node;
      node->next = node->prev = nullptr;
    }
    else
    {
      node->next = head;
      node->prev = nullptr;
      head->prev = node;
      head = node;
    }
  }

  // Remove the least recently used node (from the tail)
  Node *removeTail()
  {
    if (!tail)
      return nullptr;
    Node *node = tail;
    tail = tail->prev;

    if (tail)
      tail->next = nullptr;
    else
      head = nullptr;

    return node;
  }

public:
  // Constructor to initialize cache with a given capacity
  explicit LRUCache(int cap) : capacity(cap), head(nullptr), tail(nullptr) {}

  // Destructor to free memory
  ~LRUCache()
  {
    while (head)
    {
      Node *temp = head;
      head = head->next;
      delete temp;
    }
  }

  // Get the value of the key if it exists in the cache, else return -1
  int get(int key)
  {
    if (cache.find(key) == cache.end())
    {
      return -1; // Key not found
    }

    Node *node = cache[key];
    moveToHead(node); // Move accessed node to head (most recently used)
    return node->value;
  }

  // Put a key-value pair into the cache, evicting the least recently used if necessary
  void put(int key, int value)
  {
    if (cache.find(key) != cache.end())
    {
      Node *node = cache[key];
      node->value = value;
      moveToHead(node);
    }
    else
    {
      if (cache.size() >= capacity)
      {
        Node *tailNode = removeTail(); // Remove LRU node
        if (tailNode)
        {
          cache.erase(tailNode->key);
          delete tailNode;
        }
      }

      Node *newNode = new Node(key, value);
      cache[key] = newNode;
      addToHead(newNode);
    }
  }
};

// Main function to test the LRU Cache
int main()
{
  LRUCache cache(2);
  cache.put(2, 1);
  cache.put(2, 2);
  cout << cache.get(2) << endl; // 2
  cache.put(1, 1);
  cache.put(4, 1);
  cout << cache.get(2) << endl; // -1 (evicted)
  return 0;
}