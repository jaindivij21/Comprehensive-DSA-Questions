// Leetcode: Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree

/*
 * This is a Tries Question.
 * Uses and Benefits of a Trie:
 *  - Efficiently storing large collections of strings.
 *  - Quick Searching of strings
 *  - Prefix Identification of strings.
 */

#include <iostream>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
  unordered_map<char, TrieNode *> children; // Map to store the child char and its address node
  bool isEndOfWord;                         // Flag to mark the end of a word

  // Constructor
  TrieNode()
  {
    isEndOfWord = false;
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  // Constructor
  Trie()
  {
    root = new TrieNode();
  }

  // Instance Methods

  // Method to insert a word into the trie
  void insert(const string &word)
  {
    TrieNode *currentNode = root; // Set the current node

    // Loop over the word characters
    for (const char &currentChar : word)
    {
      // Search if the current node has a currentChar child
      if (currentNode->children.find(currentChar) == currentNode->children.end())
      {
        // Not found: We create a new node
        currentNode->children[currentChar] = new TrieNode();
      }
      currentNode = currentNode->children[currentChar];
    }

    currentNode->isEndOfWord = true;
  }

  // Method to search a word in the trie
  bool search(const string &word)
  {
    TrieNode *currentNode = root; // Set the current node

    // Loop over the word characters
    for (const char &currentChar : word)
    {
      // Search if the current node has a currentChar child
      if (currentNode->children.find(currentChar) == currentNode->children.end())
      {
        // Not found: Return false
        return false;
      }
      currentNode = currentNode->children[currentChar];
    }

    return currentNode->isEndOfWord;
  }

  // Method to identify if a prefix is present in the trie
  bool startsWith(const string &prefix)
  {
    TrieNode *currentNode = root; // Set the current node

    // Loop over the prefix characters
    for (const char &currentChar : prefix)
    {
      // Search if the current node has a currentChar child
      if (currentNode->children.find(currentChar) == currentNode->children.end())
      {
        // Not found: Return false
        return false;
      }
      currentNode = currentNode->children[currentChar];
    }

    return true;
  }
};

int main()
{
  Trie trie;

  // Insert words
  trie.insert("cat");
  trie.insert("car");
  trie.insert("dog");

  // Search for words
  cout << boolalpha;                                          // Print boolean values as true/false
  cout << "Search for 'cat': " << trie.search("cat") << endl; // true
  cout << "Search for 'car': " << trie.search("car") << endl; // true
  cout << "Search for 'dog': " << trie.search("dog") << endl; // true
  cout << "Search for 'bat': " << trie.search("bat") << endl; // false

  // Check prefixes
  cout << "Prefix 'ca': " << trie.startsWith("ca") << endl; // true
  cout << "Prefix 'do': " << trie.startsWith("do") << endl; // true
  cout << "Prefix 'ba': " << trie.startsWith("ba") << endl; // false

  return 0;
}