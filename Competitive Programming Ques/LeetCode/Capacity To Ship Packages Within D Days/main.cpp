// Capacity To Ship Packages Within D Days
// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

#include <iostream>
#include <vector>

using namespace std;

// Function that checks that if the capacity per day is given, with weights, can everything be
// shipped in given days
bool isPossibleInDays(vector<int> &weights, int days, int capacityPerDay)
{
  int totalDays = 0;
  int tempSum = 0;
  for (int i = 0; i < weights.size(); i++)
  {
    if (weights[i] > capacityPerDay)
    {
      return false;
    }

    if (tempSum + weights[i] > capacityPerDay)
    {
      totalDays++;
      tempSum = 0;
    }

    tempSum += weights[i];
  }
  totalDays++;

  return totalDays > days;
}

// Brute Force Solution
int shipWithinDays(vector<int> &weights, int days)
{
  int totalWeight = 0;
  for (auto i : weights)
  {
    totalWeight += i;
  }
  int minCapacityPerDay = totalWeight / days;

  while (!isPossibleInDays(weights, days, minCapacityPerDay))
  {
    minCapacityPerDay++;
  }

  return minCapacityPerDay;
}

int main()
{
  int size;
  cin >> size;
  vector<int> weights(size);

  for (int i = 0; i < size; i++)
  {
    cin >> weights[i];
  }

  int days;
  cin >> days;

  cout << shipWithinDays(weights, days) << endl;

  return 0;
}