// Leetcode: https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition/
// Maximum Number of Groups Entering a Competition

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maximumGroups(vector<int> &grades)
  {
    int noOfStudents = grades.size();
    if (noOfStudents <= 2)
      return 1;

    sort(grades.begin(), grades.end());

    int groups = 1;
    int lastGroupSize = 1;
    int lastGroupSum = grades[0];

    int i = 1;
    int runningSum = 0;
    int runningSize = 0;
    while (i < grades.size())
    {
      if (runningSum > lastGroupSum && runningSize > lastGroupSize && noOfStudents - i > runningSize)
      {
        groups++;
        lastGroupSize = runningSize;
        lastGroupSum = runningSum;

        runningSum = 0;
        runningSize = 0;
      }
      else
      {
        runningSum += grades[i];
        runningSize++;
        i++;
      }
    }

    if (runningSum > lastGroupSum && runningSize > lastGroupSize)
      groups++;

    return groups;
  }
};

class Solution2
{
public:
  int maximumGroups(vector<int> &grades)
  {
    int groups = 0;
    int currentGroupSize = 1;
    for (int i = 0; i < grades.size(); i += currentGroupSize)
    {
      groups++;
      currentGroupSize++;
    }
    return groups;
  }
};

int main()
{
  Solution sol;
  vector<int> grades = {8, 8};
  cout << sol.maximumGroups(grades) << endl;

  return 0;
}