// Palindrome Partitioning
// https://leetcode.com/problems/palindrome-partitioning/

#include <iostream>

using namespace std;

// Function to check if a string is palindrome
bool checkPalindrome(const string &s)
{
  int size = s.size();

  for (int i = 0; i < size; i++)
  {
    if (s[i] != s[size - 1 - i])
    {
      return false;
    }
  }

  return true;
}

void backtrack(string s, int start, vector<string> &temp, vector<vector<string>> &ans)
{
  if (start == s.size())
  {
    // Base Cases
    ans.push_back(temp);
    return;
  }

  // Recursive Cases
  for (int i = start; i < s.size(); i++)
  {
    // Try to partition at each index
    string toBeChecked = s.substr(start, i - start + 1);
    if (checkPalindrome(toBeChecked))
    {
      temp.push_back(toBeChecked);
      backtrack(s, i + 1, temp, ans);
      temp.pop_back();
    }
  }
}

vector<vector<string>> partition(string s)
{
  vector<vector<string>> ans;
  vector<string> temp;
  backtrack(s, 0, temp, ans);
  return ans;
}

int main()
{
  string s;
  cin >> s;

  vector<vector<string>> ans = partition(s);
}