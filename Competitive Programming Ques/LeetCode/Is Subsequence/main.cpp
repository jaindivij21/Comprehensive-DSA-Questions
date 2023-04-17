// Leetcode:  Is Subsequence
// https://leetcode.com/problems/is-subsequence/

#include <iostream>
using namespace std;

// Naive solution
bool isSubsequence(string s, string t)
{
  int ptr1 = 0;

  // iterate over the string t
  for (int i = 0; i < t.size(); i++)
  {
    if (t[i] == s[ptr1])
    {
      ptr1++;
    }
  }

  if (ptr1 >= s.size())
    return true;
  return false;
}

int main()
{
  string s = "abc";
  string t = "ahbgdc";
  cout << isSubsequence(s, t) << endl;
  return 0;
}