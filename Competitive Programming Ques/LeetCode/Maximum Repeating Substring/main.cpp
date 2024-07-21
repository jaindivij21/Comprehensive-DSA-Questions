// Leetcode: Maximum Repeating Substring
// https://leetcode.com/problems/maximum-repeating-substring/

#include <iostream>

using namespace std;

class Solution
{
  /*
   Time Complexity: O(N)
   Space Complexity: O(1)
  */
public:
  int maxRepeating(const string &sequence, const string &word)
  {
    int maxRepeatCount = 0, currentRepeatCount = 0;
    int seqSize = sequence.size();
    int wordSize = word.size();

    // Iterate over each character in the sequence
    for (int i = 0; i <= seqSize - wordSize; i++)
    {
      if (sequence.substr(i, wordSize) == word)
      {
        currentRepeatCount++;
        i += (wordSize - 1);
      }
      else
      {
        if (currentRepeatCount)
        {
          maxRepeatCount = max(maxRepeatCount, currentRepeatCount);
          currentRepeatCount = 0;
          i -= wordSize - 1;
        }
      }
    }
    maxRepeatCount = max(maxRepeatCount, currentRepeatCount);

    return maxRepeatCount;
  }
};

int main()
{
  string sequence, word;
  cin >> sequence >> word;

  Solution s;
  cout << s.maxRepeating(sequence, word) << endl;

  return 0;
}
