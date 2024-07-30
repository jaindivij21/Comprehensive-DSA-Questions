// Leetcode: Minimum Deletions to Make String Balanced
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int minimumDeletions(string s)
  {
    int n = s.size();
    vector<int> aToRight(n, 0); // aToRight[i] will store the number of 'a's to the right of index i
    vector<int> bToLeft(n, 0);  // bToLeft[i] will store the number of 'b's to the left of index i

    // First pass: Count the number of 'a's to the right of each element
    int aCount = 0;
    for (int i = n - 1; i >= 0; --i)
    {
      aToRight[i] = aCount;
      if (s[i] == 'a')
      {
        aCount++;
      }
    }

    // Second pass: Count the number of 'b's to the left of each element
    int bCount = 0;
    for (int i = 0; i < n; ++i)
    {
      bToLeft[i] = bCount;
      if (s[i] == 'b')
      {
        bCount++;
      }
    }

    // Third pass: Calculate the minimum number of deletions
    int minDeletions = n;
    for (int i = 0; i < n; ++i)
    {
      minDeletions = min(minDeletions, aToRight[i] + bToLeft[i]);
    }

    return minDeletions;
  }
};

int main()
{
  string str = "aababbab";

  Solution s;
  cout << s.minimumDeletions(str) << endl;
  return 0;
}