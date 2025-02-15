// Leetcode: Element Appearing More Than 25% In Sorted Array
// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

#include <iostream>

using namespace std;

class Solution
{
public:
  int findSpecialInteger(vector<int> &arr)
  {
    int n = arr.size();
    int threshold = floor(n / 4.0);

    int currNumCount = 1;
    int currNum = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
      if (currNumCount > threshold)
        return currNum;

      if (arr[i] != arr[i - 1])
      {
        currNumCount = 1;
        currNum = arr[i];
      }
      else
      {
        currNumCount++;
      }
    }

    return currNumCount > threshold ? currNum : -1;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {1, 2, 3, 3};

  cout << s.findSpecialInteger(nums) << endl;

  return 0;
}