// Remove K Digits: Leetcode
// https://leetcode.com/problems/remove-k-digits/description/

// Description: This is a greedy problem?
// If at every step we can ensure that the number is smallest, then the overall number will be smallest as well.

#include <iostream>
#include <stack>

using namespace std;

// Method to produce the smallest number post removing k digits from a string num
string removeKdigits(string num, int k)
{
  // If the num length is equal to k or k is 0
  if (num.length() <= k || k == 0)
  {
    num = k == 0 ? num : "0";
    return num;
  }

  // Make a stack
  stack<char> s;

  s.push(num[0]); // Push the initial element into the stack

  // Loop over the entire string num to keep them adding into our stack whilst excluding k digits
  for (int i = 1; i < num.length(); i++)
  {
    while (k > 0 && !s.empty() && num[i] < s.top())
    {
      k--;
      s.pop();
    }
    s.push(num[i]);
  }

  // Edge case where the number is in increasing order like 12345 - In this case we need to remove the last k digits
  // as the earlier loop will have only pushed the digits into the stack
  while (k > 0)
  {
    s.pop();
    k--;
  }

  // Pop the elements from the stack and add them to the result string
  string res = "";
  while (!s.empty())
  {
    res += s.top();
    s.pop();
  }

  // Reverse the stack to get the smallest number
  reverse(res.begin(), res.end());

  // Remove only the leading zeroes
  int i = 0;
  while (res[i] == '0')
  {
    i++;
  }
  res.erase(0, i);

  return res.length() == 0 ? "0" : res;
}

int main()
{
  string num;
  int k;

  cout << "Enter the number: ";
  cin >> num;

  cout << "Enter the number of digits to remove: ";
  cin >> k;

  cout << "The smallest number after removing " << k << " digits is: " << removeKdigits(num, k) << endl;

  return 0;
}