// Leetcode: Unique Number of Occurrences
// https://leetcode.com/problems/unique-number-of-occurrences

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool uniqueOccurrences(vector<int> &arr)
  {
    unordered_map<int, int> freq;
    unordered_set<int> freqCount;

    for (auto i : arr)
    {
      freq[i]++;
    }

    for (auto i : freq)
    {
      if (freqCount.contains(i.second))
      {
        return false;
      }
      freqCount.insert(i.second);
    }

    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {1, 2, 2, 1, 1, 3};

  cout << sol.uniqueOccurrences(arr) << endl;

  return 0;
}