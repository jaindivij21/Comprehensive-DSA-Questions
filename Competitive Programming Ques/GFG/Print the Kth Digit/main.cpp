// Print the Kth Digit
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  unsigned long long fastExp(int a, int b)
  {
    unsigned long long ans = 1;
    while (b > 0)
    {
      if ((b & 1) == 1)
      {
        ans *= a;
      }
      b >>= 1;
      a = a * a;
    }
    return ans;
  }

  int kthDigit(int A, int B, int K)
  {
    long long exp = fastExp(A, B);
    cout << exp << endl;
    int ans;
    while (K--)
    {
      ans = exp % 10;
      exp /= 10;
    }
    return ans;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long int A, B, K;
    cin >> A >> B >> K;
    Solution ob;
    cout << ob.kthDigit(A, B, K) << endl;
  }
  return 0;
}