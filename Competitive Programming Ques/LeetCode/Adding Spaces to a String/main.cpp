// Leetcode: Adding Spaces to a String
// https://leetcode.com/problems/adding-spaces-to-a-string

#include <iostream>

using namespace std;

class Solution
{
public:
  string addSpaces(string s, vector<int> &spaces)
  {
    // If there are no spaces to add, return the original string.
    if (spaces.empty())
      return s;

    string result;

    // Pointers to iterate through the string `s` and the spaces vector.
    int i = 0;
    int j = 0;

    // Iterate through the string `s`.
    while (i < s.size())
    {
      // If the current (i) index matches the next space position, add a space.
      if (j < spaces.size() && i == spaces[j])
      {
        result += " ";
        j++; // Move to the next space position.
      }
      // Add the current character to the result.
      result += s[i];
      i++;
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "LeetcodeHelpsMeLearn";
  vector<int> spaces = {8, 13, 15};
  string result = sol.addSpaces(s, spaces);

  return 0;
}