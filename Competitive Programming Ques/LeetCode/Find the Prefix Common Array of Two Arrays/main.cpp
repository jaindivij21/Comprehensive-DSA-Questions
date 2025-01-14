// Leetcode: Find the Prefix Common Array of Two Arrays
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
  {
    int currFreq = 0;
    vector<int> ans;
    unordered_map<int, int> map;

    for (int i = 0; i < A.size(); i++)
    {
      if (map.find(A[i]) == map.end())
        map[A[i]] = 1;
      else
      {
        map[A[i]]++;
        currFreq += (map[A[i]] - 1);
      }

      if (map.find(B[i]) == map.end())
        map[B[i]] = 1;
      else
      {
        map[B[i]]++;
        currFreq += (map[B[i]] - 1);
      }

      ans.push_back(currFreq);
    }

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> A = {1, 3, 2, 4};
  vector<int> B = {3, 1, 2, 4};

  vector<int> result = s.findThePrefixCommonArray(A, B);

  return 0;
}