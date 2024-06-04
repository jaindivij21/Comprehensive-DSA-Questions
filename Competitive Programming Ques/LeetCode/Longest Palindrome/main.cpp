// Leetcode: Longest Palindrome
// https://leetcode.com/problems/longest-palindrome

#include <iostream>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s)
{
  unordered_map<int, int> counts;
  int count = 0;
  for (char i : s)
  {
    if (counts.find(i) == counts.end())
    {
      counts[i] = 1;
    }
    else
    {
      counts[i]++;
    }
  }

  bool ifOne = false;
  for (auto const &p : counts)
  {
    if (!ifOne && p.second % 2 == 1)
    {
      ifOne = true;
    }

    count += (p.second / 2) * 2;
  }

  return ifOne ? count + 1 : count;
}

int main()
{
  string s;
  cin >> s;

  cout << longestPalindrome(s) << endl;

  return 0;
}