// Sum of Digit is Pallindrome or not
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // basic program to reverse a number
  int reverse(long long sum)
  {
    long long reverse = 0;
    while (sum != 0)
    {
      long long lastNum = sum % 10;
      sum /= 10;
      reverse = reverse * 10 + lastNum;
    }
    return reverse;
  }

  int isPalindrome(long long sum)
  {
    if (sum == reverse(sum))
      return 1;
    else
      return 0;
  }

  int isDigitSumPalindrome(int N)
  {
    long long sum = 0;
    while (N != 0)
    {
      sum += (N % 10);
      N /= 10;
    }
    if (isPalindrome(sum))
      return 1;
    else
      return 0;
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N;
    Solution ob;
    cout << ob.isDigitSumPalindrome(N) << "\n";
  }
}