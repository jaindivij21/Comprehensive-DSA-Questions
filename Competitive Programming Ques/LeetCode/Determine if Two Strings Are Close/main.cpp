// Leetcode: Determine if Two Strings Are Close
// https://leetcode.com/problems/determine-if-two-strings-are-close

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool closeStrings(string &word1, string &word2)
  {
    if (word1.size() != word2.size())
      return false;

    unordered_map<char, int> freq1;
    unordered_map<char, int> freq2;

    for (int i = 0; i < word1.size(); i++)
    {
      freq1[word1[i]]++;
      freq2[word2[i]]++;
    }

    unordered_map<int, int> freqCount;
    for (auto &itr : freq2)
    {
      if (freq1.find(itr.first) == freq1.end())
        return false;

      freqCount[itr.second]++;
    }

    freq2.clear();
    for (auto &itr : freq1)
    {
      if (freqCount.find(itr.second) != freqCount.end() && freqCount[itr.second] != 0)
      {
        freqCount[itr.second]--;
      }
      else
      {
        return false;
      }
    }

    return true;
  }
};

int main()
{
  Solution s;

  string word1 = "abc";
  string word2 = "bca";

  cout << s.closeStrings(word1, word2) << endl;

  return 0;
}