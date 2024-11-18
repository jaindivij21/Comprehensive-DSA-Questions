// Leetcode: Defuse the Bomb
// https://leetcode.com/problems/defuse-the-bomb

#include <iostream>

using namespace std;

class Solution
{
public:
  vector<int> decrypt(vector<int> &code, int k)
  {
    int originalCodeSize = code.size();
    vector<int> ans(originalCodeSize, 0);

    if (k == 0)
      return ans;

    code.insert(code.end(), code.begin(), code.end());

    if (k > 0)
    {
      int i = 0, j = 0;
      int runningSum = 0;

      while (k--)
      {
        j++;
        runningSum += code[j];
      }

      while (i < originalCodeSize)
      {
        ans[i] = runningSum;
        i++;
        j++;
        runningSum += (code[j] - code[i]);
      }
    }
    else
    {
      int i = code.size() - 1, j = code.size() - 1;
      int runningSum = 0;
      k *= -1;

      while (k--)
      {
        j--;
        runningSum += code[j];
      }

      while (i > originalCodeSize)
      {
        ans[i - originalCodeSize] = runningSum;
        i--;
        j--;
        runningSum += (code[j] - code[i]);
      }
    };

    return ans;
  }
};

int main()
{
  Solution s;
  vector<int> code = {5, 7, 1, 4};
  int k = 3;

  vector<int> result = s.decrypt(code, k);

  return 0;
}