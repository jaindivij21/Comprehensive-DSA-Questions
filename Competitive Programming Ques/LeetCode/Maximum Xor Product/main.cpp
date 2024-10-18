// Leetcode: Maximum Xor Product
// https://leetcode.com/problems/maximum-xor-product
// https://algo.monster/liteproblems/2939 : Hard

#include <iostream>

#define ll long long
#define MOD 1000000007
using namespace std;

class Solution
{
public:
  int maximumXorProduct(long long a, long long b, int n)
  {
    // Keep the extra bits (more than n) same, make all the rest of them as 0
    ll ax = (a >> n) << n;
    ll bx = (b >> n) << n;

    // Iterate over n bits from the end
    for (int i = n - 1; i >= 0; i--)
    {
      ll bitA = (a >> i) & 1;
      ll bitB = (b >> i) & 1;

      if (bitA == bitB)
      {
        // If both the bits are same
        ax |= (1LL << i);
        bx |= (1LL << i);
      }
      else if (ax < bx)
      {
        // Balancing Act: Make ax bigger
        ax |= 1LL << i;
      }
      else
      {
        // Balancing Act: Make bx bigger
        bx |= 1LL << i;
      }
    }

    ax %= MOD;
    bx %= MOD;

    // Return the product of `aXor` and `bXor` under modulo
    return (ax * bx) % MOD;
  }
};

int main()
{
  Solution sol;
  cout << sol.maximumXorProduct(2, 5, 2) << endl;

  return 0;
}
