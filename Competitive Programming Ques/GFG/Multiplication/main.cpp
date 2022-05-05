#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> getTable(int N)
  {
    vector<int> ans;
    for (int i = 1; i <= 10; i++)
      ans.push_back(i * N);
    return ans;
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
    vector<int> ans = ob.getTable(N);
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] << " ";
    cout << "\n";
  }
  return 0;
}