// Leetcode: Remove Sub-Folders from the Filesystem
// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem

#include <vector>
#include <unordered_map>

using namespace std;

class TrieNode
{
public:
  bool isEnd;
  unordered_map<string, TrieNode *> children;

  TrieNode()
  {
    isEnd = false;
  }
};

class Trie
{
public:
  TrieNode *root;

  Trie()
  {
    root = new TrieNode;
  }

  void insert(const vector<string> &words)
  {
    TrieNode *currentNode = root;
    for (auto i : words)
    {
      if (currentNode->children.find(i) == currentNode->children.end())
      {
        currentNode->children[i] = new TrieNode();
      }
      currentNode = currentNode->children[i];
    }
    currentNode->isEnd = true;
  }

  void compressTrie(vector<string> &ans, string runnStr, TrieNode *currNode)
  {
    // Base Case
    if (currNode->isEnd)
    {
      ans.push_back(runnStr);
      return;
    }

    // Recursive Cases
    for (const auto &i : currNode->children)
    {
      compressTrie(ans, runnStr + "/" + i.first, i.second);
    }
  }
};

class Solution
{
public:
  vector<string> removeSubfolders(vector<string> &folder)
  {
    Trie t;

    for (auto i : folder)
    {
      vector<string> s = splitString(i);

      t.insert(s);
    }

    vector<string> ans;
    t.compressTrie(ans, "", t.root);

    return ans;
  }

private:
  vector<string> splitString(string &s)
  {
    vector<string> splittedString;

    string curr;
    for (auto i : s)
    {
      if (i == '/')
      {
        if (!curr.empty())
          splittedString.push_back(curr);
        curr = "";
      }
      else
      {
        curr += i;
      }
    }
    splittedString.push_back(curr);

    return splittedString;
  }
};

int main()
{
  Solution sol;
  vector<string> folder = {"/a", "/a/b", "/c/d", "/c/d/e", "/c/f"};
  vector<string> result = sol.removeSubfolders(folder);

  return 0;
}