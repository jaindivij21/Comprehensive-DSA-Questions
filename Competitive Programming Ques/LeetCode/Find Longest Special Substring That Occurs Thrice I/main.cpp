// Leetcode: Find Longest Special Substring That Occurs Thrice I
// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int maximumLength(string &s)
  {
    int left = 1;         // Minimum possible length of a special substring
    int right = s.size(); // Maximum possible length of a special substring
    int maxSpecialSubstringLength = -1;

    // Binary search to find the maximum length of a special substring
    while (left <= right)
    {
      int midLength = left + (right - left) / 2;

      // Check if three special substrings of length midLength exist
      if (hasThreeSpecialSubstrings(s, midLength))
      {
        maxSpecialSubstringLength = max(maxSpecialSubstringLength, midLength);
        left = midLength + 1; // Search for a longer substring
      }
      else
      {
        right = midLength - 1; // Search for a shorter substring
      }
    }

    return maxSpecialSubstringLength;
  }

private:
  // Helper function to check if there are at least three special substrings of a given length
  bool hasThreeSpecialSubstrings(string &s, int substringLength)
  {
    unordered_map<char, int> substringCount; // Count of special substrings per character
    char currentChar;
    int currentCharLength = 0;

    for (int i = 0; i < s.size(); ++i)
    {
      currentChar = s[i];

      // Count consecutive characters
      while (i < s.size() && s[i] == currentChar)
      {
        currentCharLength++;
        i++;
      }
      i--; // Adjust index after the inner while loop

      // Calculate the number of valid special substrings for the current character
      int validSubstrings = currentCharLength - substringLength + 1;
      if (validSubstrings > 0)
      {
        substringCount[currentChar] += validSubstrings;

        // If any character has at least 3 valid substrings, return true
        if (substringCount[currentChar] >= 3)
        {
          return true;
        }
      }

      // Reset for the next character
      currentCharLength = 0;
    }

    return false;
  }
};

int main()
{
  Solution sol;
  string s = "abcdef";

  cout << sol.maximumLength(s) << endl;

  return 0;
}