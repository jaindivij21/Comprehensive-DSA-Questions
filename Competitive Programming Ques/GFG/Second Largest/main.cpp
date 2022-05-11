#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int print2largest(int arr[], int n)
  {
    // if the size is less than 2, not possible to have less a second largest element
    if (n < 2)
    {
      return -1;
    }

    // Make them eql to INT_MIN
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    // Do just one iteration
    for (int i = 0; i < n; i++)
    {
      if (arr[i] > largest)
      {
        secondLargest = largest;
        largest = arr[i];
      }
      else if (arr[i] > secondLargest && arr[i] < largest)
      {
        secondLargest = arr[i];
      }
    }
    // if for
    if (secondLargest == INT_MIN)
      return -1;
    return secondLargest;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.print2largest(arr, n);
    cout << ans << "\n";
  }
  return 0;
}