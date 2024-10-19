// Leetcode: Merge Strings Alternately
// https://leetcode.com/problems/merge-strings-alternately

#include <iostream>

using namespace std;

class Solution
{
public:
  string mergeAlternately(string word1, string word2)
  {
    string ans;

    int i = 0;
    for (; i < min(word1.size(), word2.size()); i++)
    {
      ans += word1[i];
      ans += word2[i];
    }

    while (i < word1.size())
      ans += word1[i++];
    while (i < word2.size())
      ans += word2[i++];

    return ans;
  }
};

int main()
{
  Solution s;
  string word1 = "abc";
  string word2 = "pqr";
  cout << s.mergeAlternately(word1, word2) << endl;

  return 0;
}
