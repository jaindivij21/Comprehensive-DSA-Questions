// Leetcode: Check If N and Its Double Exist
// https://leetcode.com/problems/check-if-n-and-its-double-exist

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  bool checkIfExist(vector<int> &arr)
  {
    unordered_set<int> set;

    for (auto i : arr)
    {
      if (set.contains(i * 2) || (i % 2 == 0 && set.contains(i / 2)))
      {
        return true;
      }
      set.insert(i);
    }

    return false;
  }
};

int main()
{
  Solution sol;
  vector<int> arr = {10, 2, 5, 3};
  cout << sol.checkIfExist(arr) << endl;

  return 0;
}