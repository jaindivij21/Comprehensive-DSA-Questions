#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  int Nth_term(int a, int r, int n)
  {
    const int MAX = 1e9 + 7;
    return (a * power(r, n - 1)) % MAX;
  }

private:
  int const p = 10e9 + 7;
  int power(long long x, unsigned int y)
  {
    int res = 1; // Initialize result

    x = x % p; // Update x if it is more than or
               // equal to p

    if (x == 0)
      return 0; // In case x is divisible by p;

    while (y > 0)
    {
      // If y is odd, multiply x with result
      if (y & 1)
        res = (res * x) % p;

      // y must be even now
      y = y >> 1; // y = y/2
      x = (x * x) % p;
    }
    return res;
  }
};

int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int a, r, n;
    cin >> a >> r >> n;
    Solution ob;
    int ans = ob.Nth_term(a, r, n);
    cout << ans << "\n";
  }
  return 0;
}