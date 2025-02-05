// Leetcode: Check if One String Swap Can Make Strings Equal
// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool areAlmostEqual(string &s1, string &s2)
  {
    if (s1 == s2)
      return true;

    if (s1.length() != s2.length())
      return false;

    int diff = 0;
    unordered_map<char, int> m;
    for (int i = 0; i < s1.length(); i++)
    {
      if (s1[i] != s2[i])
      {
        diff++;
        m[s1[i]]++;
        m[s2[i]]--;
      }
    }

    if (diff != 2)
      return false;

    for (auto it = m.begin(); it != m.end(); it++)
    {
      if (it->second != 0)
        return false;
    }

    return true;
  }
};

int main()
{
  Solution s;
  string s1 = "bank";
  string s2 = "kanb";

  cout << s.areAlmostEqual(s1, s2) << endl;

  return 0;
}