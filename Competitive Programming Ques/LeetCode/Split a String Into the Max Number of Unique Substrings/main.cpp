// Leetcode: Split a String Into the Max Number of Unique Substrings
// https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  // Function to find the maximum number of unique substrings
  int maxUniqueSplit(string &str)
  {
    unordered_set<string> seenSubstrings;
    return findMaxUniqueSplits(str, seenSubstrings, 0);
  }

private:
  // Helper function to recursively find the maximum number of unique substrings
  int findMaxUniqueSplits(string &str, unordered_set<string> &seenSubstrings, int startIndex)
  {
    // Base case: if we've processed the entire string, return 0
    if (startIndex >= str.size())
      return 0;

    string currentSubstring;
    int maxUniqueCount = 0;

    // Iterate over the string
    for (int i = startIndex; i < str.size(); i++)
    {
      currentSubstring += str[i];

      // If the substring is already seen, skip it to ensure uniqueness
      if (seenSubstrings.find(currentSubstring) != seenSubstrings.end())
        continue;

      // Add the current substring to the set of seen substrings
      seenSubstrings.insert(currentSubstring);

      // Recur for the rest of the string, starting from the next character (i + 1)
      int currentCount = 1 + findMaxUniqueSplits(str, seenSubstrings, i + 1);

      // Remove the current substring from the set to backtrack and try other combinations
      seenSubstrings.erase(currentSubstring);

      // Update the maximum unique count
      maxUniqueCount = max(maxUniqueCount, currentCount);
    }

    return maxUniqueCount;
  }
};

int main()
{
  Solution s;
  string st = "ababccc";
  cout << s.maxUniqueSplit(st) << endl;

  return 0;
}