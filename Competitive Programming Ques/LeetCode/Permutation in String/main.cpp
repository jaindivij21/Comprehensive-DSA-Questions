// Leetcode: Permutation in String
// https://leetcode.com/problems/permutation-in-string

#include <iostream>

using namespace std;

class Solution
{
public:
  bool checkInclusion(string &s1, string &s2)
  {
    int windowSize = s1.size();
    int n = s2.size();

    // If s1 is longer than s2, no permutation can exist
    if (windowSize > n)
      return false;

    // Frequency map for characters in s1
    vector<int> s1Freq(26, 0), windowFreq(26, 0);

    // Initialize frequency maps for s1 and the first window of s2
    for (int i = 0; i < windowSize; ++i)
    {
      s1Freq[s1[i] - 'a']++;     // frequency for s1
      windowFreq[s2[i] - 'a']++; // first window in s2
    }

    // Sliding window approach
    for (int i = windowSize; i < n; ++i)
    {
      // Check if the current window matches s1's frequency map
      if (s1Freq == windowFreq)
        return true;

      // Slide the window to the right:
      // Remove the left character of the current window
      windowFreq[s2[i - windowSize] - 'a']--;
      // Add the next character to the right of the window
      windowFreq[s2[i] - 'a']++;
    }

    // Final check for the last window
    return s1Freq == windowFreq;
  }
};

int main()
{
  string s1 = "ab";
  string s2 = "eidbaooo";
  Solution sol;
  cout << sol.checkInclusion(s1, s2) << endl;

  return 0;
}