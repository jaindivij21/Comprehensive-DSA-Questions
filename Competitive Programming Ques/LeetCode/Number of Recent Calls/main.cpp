// Leetcode: Number of Recent Calls
// https://leetcode.com/problems/number-of-recent-calls

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter
{
public:
  queue<int> q;

  RecentCounter() = default;

  int ping(int t)
  {
    int l = t - 3000;
    int r = t;

    q.push(t);
    while (!q.empty() && (q.front() < l || q.front() > r))
    {
      q.pop();
    }

    return q.size();
  }
};

int main()
{
  RecentCounter rc;
  cout << rc.ping(1) << endl;
  cout << rc.ping(100) << endl;
  cout << rc.ping(3001) << endl;
  cout << rc.ping(3002) << endl;

  return 0;
}