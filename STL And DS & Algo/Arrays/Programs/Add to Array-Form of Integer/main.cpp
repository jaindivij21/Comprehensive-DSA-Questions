// Add to Array-Form of Integer
// https://leetcode.com/problems/add-to-array-form-of-integer/

#include <iostream>
#include <vector>

using namespace std;

vector<int> addToArrayForm(vector<int> &num, int k)
{
  for (int i = num.size() - 1; i >= 0; i--)
  {
    num[i] += k;
    k = num[i] / 10;
    num[i] %= 10;
  }
  while (k > 0)
  {
    num.insert(num.begin(), k % 10);
    k /= 10;
  }
  return num;
}

int main()
{
  int n;
  cin >> n;
  int k;
  cin >> k;
  vector<int> nums(n);

  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }

  vector<int> ans = addToArrayForm(nums, k) << endl;

  for (auto i : ans)
  {
    cout << i << " ";
  }

  return 0;
}