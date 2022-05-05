// Program to calculate the Nth term of a GP
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const long long MAX = 1e9 + 7;

  // calculate the Nth term
  int Nth_term(int a, int r, int n)
  {
    return (a * exponent(r, n - 1)) % MAX;
  }

private:
  // function to calculate the modulo exponentiation
  long long exponent(long long a, long long b)
  {
    a = a % MAX;
    long long ans = 1;
    if (b == 0)
      return ans;
    while (b > 0)
    {
      if (b & 1)
      {
        // means the right most bit is 1, hence update the ans
        ans = (ans * a) % MAX;
      }
      // right shift the b
      b = b >> 1;
      // in every iteration square a
      a = (a * a) % MAX;
    }
    return ans % MAX;
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