// https://practice.geeksforgeeks.org/problems/series-ap5310/1
// Find the nth term of an AP Series if the first and second term is given

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int nthTermOfAP(int A1, int A2, int N)
  {
    int diff = A2 - A1;
    return A1 + (N - 1) * diff;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int A1, A2, N;
    cin >> A1 >> A2 >> N;
    Solution ob;
    cout << ob.nthTermOfAP(A1, A2, N) << "\n";
  }
}