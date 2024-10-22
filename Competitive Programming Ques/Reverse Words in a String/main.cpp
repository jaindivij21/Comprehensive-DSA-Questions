// Leetcode: Reverse Words in a String
// https://leetcode.com/problems/reverse-words-in-a-string

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string reverseWords(string &s)
  {
    vector<string> words;

    int i = 0;
    while (i < s.size())
    {
      if (i < s.size() && s[i] == ' ')
      {
        while (s[i] == ' ')
        {
          i++;
        }
      }
      else
      {
        string word;
        while (i < s.size() && s[i] != ' ')
        {
          word += s[i];
          i++;
        }
        words.push_back(word);
      }
    }

    if (words.size() == 0)
      return "";

    string ans = words[words.size() - 1];
    for (int i = words.size() - 2; i >= 0; i--)
    {
      ans += (' ' + words[i]);
    }

    return ans;
  }
};

int main()
{
  Solution sol;
  string s = "  hello world  ";
  cout << sol.reverseWords(s);

  return 0;
}