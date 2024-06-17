// Leetcode: Sum of Square Numbers
// https://leetcode.com/problems/sum-of-square-numbers

#include <iostream>

typedef long long int ll;

using namespace std;

// Binary Search to find an element in a range
bool binarySearch(ll squareOfElementToFind, ll start, ll end)
{
  while (start <= end)
  {
    ll mid = start + ((end - start) / 2);

    if (mid * mid == squareOfElementToFind)
      return true;
    else if (mid * mid > squareOfElementToFind)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return false;
}

// a^2 + b^2 = c => Which means for an integer a, b = sqrt(c - a^2) should also be an integer
bool judgeSquareSum(int c)
{
  // For all the integers i
  for (ll i = 0; i * i <= c; i++)
  {
    // Find if an integer j exists such that j = sqrt(c - a^2) or j^2 = c - a^2
    // Basically we need to find if there is a number j * j is a perfect square
    // We can find it optimally using binary search by searching for between [0, c - a^2]
    ll m = c - i * i;
    if (binarySearch(m, 0, m))
    {
      return true;
    }
  }

  return false;
}

int main()
{
  int c;
  cout << judgeSquareSum(c) << endl;
  return 0;
}