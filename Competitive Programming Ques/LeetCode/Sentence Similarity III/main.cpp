// Leetcode: Sentence Similarity III
// https://leetcode.com/problems/sentence-similarity-iii
// https://www.youtube.com/watch?v=s1XqPeVPJQE

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // Function to check if two sentences are similar
  bool areSentencesSimilar(string &sentence1, string &sentence2)
  {
    // Split both sentences into words
    vector<string> s1 = splitString(sentence1);
    vector<string> s2 = splitString(sentence2);

    // If both sentences are identical or either one is empty, they are similar
    if (s1 == s2 || s1.empty() || s2.empty())
      return true;

    // If the sizes of the sentences are equal but the words are different, they are not similar
    if (s1.size() == s2.size())
      return false;

    // Determine which sentence is longer and check for dissimilarities
    if (s1.size() < s2.size())
    {
      return isDissimilar(s1, s2);
    }
    else
    {
      return isDissimilar(s2, s1);
    }
  }

private:
  // Helper function to check for dissimilarity by comparing prefixes and suffixes
  bool isDissimilar(const vector<string> &shorter, const vector<string> &longer)
  {
    int n1 = shorter.size(), n2 = longer.size();
    int start = 0;

    // Check prefix match
    while (start < n1 && shorter[start] == longer[start])
    {
      start++;
    }

    // Check suffix match
    int end = n1 - 1; // last index of shorter
    while (end >= 0 && shorter[end] == longer[n2 - (n1 - end)])
    {
      end--;
    }

    // If the whole shorter sentence is matched, they are similar
    return start > end;
  }

  vector<string> splitString(string &str, char delimiter = ' ')
  {
    vector<string> strings;

    if (str.empty())
      return strings;

    string word;
    for (auto i : str)
    {
      if (i == delimiter)
      {
        strings.push_back(word);
        word = "";
      }
      else
      {
        word += i;
      }
    }
    strings.push_back(word);

    return strings;
  }
};

int main()
{
  Solution solution;
  string sentence1 = "hello";
  string sentence2 = "hr uyello";
  cout << solution.areSentencesSimilar(sentence1, sentence2) << endl;

  return 0;
}