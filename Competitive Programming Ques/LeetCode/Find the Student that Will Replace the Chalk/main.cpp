// Leetcode: Find the Student that Will Replace the Chalk
// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
  // Method to find the student that will replace the chalk
  int chalkReplacer(vector<int> &chalk, int k)
  {
    long numOfChalks = std::reduce(chalk.begin(), chalk.end(), 0L);

    numOfChalks = k % numOfChalks;

    int i = 0;
    for (; i < chalk.size(); i++)
    {
      if (numOfChalks >= chalk[i])
      {
        numOfChalks -= chalk[i];
      }
      else
      {
        break;
      }
    }

    return i;
  }
};

int main()
{
  Solution solution;
  vector<int> chalk = {5, 1, 5};
  int k = 22;
  cout << solution.chalkReplacer(chalk, k) << endl;
  return 0;
}