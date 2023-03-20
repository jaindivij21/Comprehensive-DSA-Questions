// Leetcode: Can Place Flowers
// https://leetcode.com/problems/can-place-flowers/

#include <vector>
#include <iostream>
using namespace std;

// Helper Function
bool canPlaceAtThisIndex(vector<int> &flowerbed, int size, int index)
{
  bool canPlaceOnLeft = false;
  bool canPlaceOnRight = false;

  if (index == 0 || flowerbed[index - 1] == 0)
  {
    canPlaceOnLeft = true;
  }

  if (index == size - 1 || flowerbed[index + 1] == 0)
  {
    canPlaceOnRight = true;
  }

  return canPlaceOnLeft && canPlaceOnRight;
}

// Function to tell if n flowers can be places in the flowerbed given the constraint in the question
bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
  int count = 0;

  for (int i = 0; i < flowerbed.size(); i++)
  {
    if (flowerbed[i] == 0 && canPlaceAtThisIndex(flowerbed, flowerbed.size(), i))
    {
      count++;
      flowerbed[i] = 1;
    }
  }

  return count >= n;
}

int main()
{
  int size, n;
  cin >> size >> n;

  vector<int> arr(size);
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  cout << canPlaceFlowers(arr, n) << endl;

  return 0;
}