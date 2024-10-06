// Leetcode: Sentence Similarity
// https://leetcode.com/problems/sentence-similarity

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool areSentencesSimilar(vector<string> &s1, vector<string> &s2, vector<vector<string>> &similarPairs)
  {
    // If the sizes of the two sentences are different, they can't be similar
    if (s1.size() != s2.size())
      return false;

    // Using an unordered_multimap to store the similarity pairs
    unordered_multimap<string, string> multimap;

    // Insert all pairs in both directions into the multimap
    for (const auto &pair : similarPairs)
    {
      multimap.insert({pair[0], pair[1]}); // Forward direction
      multimap.insert({pair[1], pair[0]}); // Reverse direction (since similarity is bidirectional)
    }

    // Traverse through both sentences
    for (int i = 0; i < s1.size(); i++)
    {
      // If the words at the current index are identical, no need to check further
      if (s1[i] == s2[i])
        continue;

      // Get the range of similar words for s1[i]
      auto range = multimap.equal_range(s1[i]);

      // Check if any of the similar words match s2[i]
      bool matchFound = false;
      for (auto itr = range.first; itr != range.second; ++itr)
      {
        if (itr->second == s2[i])
        {
          matchFound = true;
          break; // No need to search further
        }
      }

      // If no match is found, the sentences are not similar
      if (!matchFound)
        return false;
    }

    // If all words are either identical or similar, return true
    return true;
  }
};

int main()
{
  Solution solution;
  vector<string> sentence1 = {"great", "acting", "skills"};
  vector<string> sentence2 = {"fine", "drama", "talent"};
  vector<vector<string>> similarPairs = {{"great", "fine"},
                                         {"drama", "acting"},
                                         {"skills", "talent"}};
  cout << solution.areSentencesSimilar(sentence1, sentence2, similarPairs) << endl;

  return 0;
}