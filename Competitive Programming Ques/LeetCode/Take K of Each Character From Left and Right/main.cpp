// Leetcode: Take K of Each Character From Left and Right
// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int takeCharacters(string s, int k)
  {
    unordered_map<char, int> totalFreq;
    int n = s.length();

    // Record frequencies
    for (char c : s)
    {
      totalFreq[c]++;
    }

    // Check if all three characters ('a', 'b', 'c') have at least k occurrences
    for (char c : {'a', 'b', 'c'})
    {
      if (totalFreq[c] < k)
        return -1;
    }

    unordered_map<char, int> windowFreq;
    int left = 0, right = 0;
    int maxWindowLen = 0;

    // Sliding window using only while loop
    while (right < n)
    {
      // Expand the window by including the current character
      windowFreq[s[right]]++;
      right++;

      // Shrink the window while the condition is invalid and left <= right
      while (left <= right && isInvalid(totalFreq, windowFreq, k))
      {
        windowFreq[s[left]]--;
        left++;
      }

      // Update the maximum window length
      maxWindowLen = max(maxWindowLen, right - left);
    }

    // Minimum characters to take out is the rest of the string
    return n - maxWindowLen;
  }

private:
  // Helper function to check if the window violates the condition
  bool isInvalid(unordered_map<char, int> &totalFreq, unordered_map<char, int> &windowFreq, int k)
  {
    for (char c : {'a', 'b', 'c'})
    {
      if (totalFreq[c] - windowFreq[c] < k)
      {
        return true; // Invalid if outside frequency of any char is less than k
      }
    }
    return false;
  }
};

int main()
{
  Solution sol;
  string s = "aabaaaacaabc";
  int k = 2;

  cout << sol.takeCharacters(s, k) << endl;

  return 0;
}