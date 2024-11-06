// Leetcode: Find The Original Array of Prefix Xor
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor

#include <iostream>

using namespace std;

using namespace std;

class Solution
{
public:
  vector<int> findArray(vector<int> &pref)
  {
    int runningAnsXOR = pref[0];

    for (int i = 1; i < pref.size(); i++)
    {
      pref[i] = runningAnsXOR ^ pref[i];
      runningAnsXOR ^= pref[i];
    }

    return pref;
  }
};

int main()
{
  Solution sol;
  vector<int> pref = {6, 3, 4, 5, 2};

  cout << (0 ^ 5 ^ 7);

  //    vector<int> res = sol.findArray(pref);

  return 0;
}