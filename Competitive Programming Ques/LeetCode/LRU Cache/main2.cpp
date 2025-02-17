// Leetcode: LRU Cache
// https://leetcode.com/problems/lru-cache/description/

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

// LRU Cache implementation using Hash Map and Doubly Linked List
class LRUCache
{
private:
  int capacity;
  list<pair<int, int>> linkedList;
  unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
  // Constructor to initialize cache with a given capacity
  explicit LRUCache(int cap) : capacity(cap) {}

  // Destructor to free memory
  ~LRUCache()
  {
    linkedList.clear();
    cache.clear();
  }

  // Get the value of the key if it exists in the cache, else return -1
  int get(int key)
  {
    if (cache.empty() || cache.find(key) == cache.end())
      return -1;

    auto nodeToReturn = cache[key];
    int value = nodeToReturn->second;

    linkedList.erase(nodeToReturn);
    linkedList.emplace_front(key, value);

    cache[key] = linkedList.begin();

    return linkedList.front().second;
  }

  // Put a key-value pair into the cache, evicting the least recently used if necessary
  void put(int key, int value)
  {
    if (cache.find(key) != cache.end())
    {
      // The node exists somewhere. we need to erase it and add it to the front
      auto nodeToErase = cache[key];
      linkedList.erase(nodeToErase);
    }
    else
    {
      if (linkedList.size() >= capacity)
      {
        // Remove the least use node and add at front
        auto lastNode = --linkedList.end();
        cache.erase(lastNode->first);
        linkedList.pop_back();
      }
    }

    linkedList.emplace_front(key, value);
    cache[key] = linkedList.begin();
  }
};

// Main function to test the LRU Cache
int main()
{

  LRUCache cache(2);
  cout << cache.get(2) << endl;
  cache.put(2, 6);
  cout << cache.get(1) << endl;
  cache.put(1, 5);
  cache.put(1, 2);
  cout << cache.get(1) << endl;
  cout << cache.get(2) << endl;

  return 0;
}