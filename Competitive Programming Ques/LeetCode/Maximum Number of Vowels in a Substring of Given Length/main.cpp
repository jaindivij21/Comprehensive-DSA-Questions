// Leetcode: Maximum Number of Vowels in a Substring of Given Length
// https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  int maxVowels(std::string &s, int &k)
  {
    // Set of vowels for quick lookup
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

    // To track the maximum number of vowels in any window
    int maxVowelCount = 0;
    // To track the number of vowels in the current window
    int currentVowelCount = 0;

    // Initialize the first window of size k
    for (int j = 0; j < k; j++)
    {
      if (vowels.contains(s[j]))
      {
        currentVowelCount++;
      }
    }

    // Set max to the count of the first window
    maxVowelCount = currentVowelCount;

    // Slide the window across the string
    for (int start = 0, end = k; end < s.size(); start++, end++)
    {
      // Remove the character going out of the window
      if (vowels.contains(s[start]))
      {
        currentVowelCount--;
      }
      // Add the new character coming into the window
      if (vowels.contains(s[end]))
      {
        currentVowelCount++;
      }

      // Update the maximum count of vowels found
      maxVowelCount = max(maxVowelCount, currentVowelCount);
    }

    // Return the maximum number of vowels in any k-length substring
    return maxVowelCount;
  }
};

int main()
{
  Solution sol;
  string s = "abciiidef";
  int k = 3;

  cout << "Max vowels in substring: " << sol.maxVowels(s, k) << endl;

  return 0;
}