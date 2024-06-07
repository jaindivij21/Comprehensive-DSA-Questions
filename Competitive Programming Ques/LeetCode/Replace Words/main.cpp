// Leetcode: Replace Words
// https://leetcode.com/problems/replace-words

#include <iostream>
#include <vector>
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

  // Class Methods
  static string replaceWords(vector<string> &dictionary, string &sentence)
  {
    string ans;

    // Make a trie data structure using the dictionary provided
    Trie trie;
    for (const string &word : dictionary)
    {
      trie.insert(word);
    }

    // Convert sentence string into array of strings
    vector<string> sentenceWords = Trie::convertStringToVector(sentence);

    // Formulate the answer string
    for (int i = 0; i < sentenceWords.size(); i++)
    {
      ans += trie.fetchPrefix(sentenceWords[i]);
      if (i != sentenceWords.size() - 1)
        ans += ' ';
    }

    return ans;
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

  // Method to identify if a prefix is present in the trie
  string fetchPrefix(const string &word)
  {
    string stringPath;
    TrieNode *currentNode = root; // Set the current node

    for (const char &currentChar : word)
    {
      if (currentNode->children.find(currentChar) == currentNode->children.end())
      {
        break; // No match found, return the entire word
      }
      stringPath += currentChar;
      currentNode = currentNode->children[currentChar];

      // Check if the current node is the end of a word
      if (currentNode->isEndOfWord)
      {
        return stringPath; // Shortest root found, return it
      }
    }

    return word;
  }

  // Helper Methods
  static vector<string> convertStringToVector(const string &sentence)
  {
    vector<string> sentenceWords;

    string word;
    for (const char &i : sentence)
    {
      if (i == ' ')
      {
        sentenceWords.push_back(word);
        word = "";
      }
      else
      {
        word += i;
      }
    }
    sentenceWords.push_back(word);

    return sentenceWords;
  }
};

int main()
{
  string sentence;
  getline(cin, sentence);

  int size;
  cin >> size;
  vector<string> dictionary(size);
  for (int i = 0; i < size; i++)
  {
    cin >> dictionary[i];
  }

  cout << Trie::replaceWords(dictionary, sentence) << endl;

  return 0;
}