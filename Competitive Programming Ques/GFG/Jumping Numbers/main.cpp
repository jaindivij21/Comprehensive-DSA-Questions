// Jumping Numbers :: Good Question

// Two approaches:
/*
  1) Brute Force : Iterate down the numbers and check if they are jumping numbers, if yes, mark it as the answer.
  2) Effective solution : BFS/DFS, understand the problem like a graph, where the start root node is 0
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Function to print the largest jumping number before the number X.
  // Start with 0 and iterate over all the jumping numbers using a graph, till the time the jumping numbers are less than X.
  // Also keep track of the maximum number till now.
  long long jumpingNums(long long X)
  {
    long long max = 0; // Because the minimum jumping number is 0
    // iterate over all the first 10 numbers (0-9) or till X if X is less 9
    for (int i = 1; i <= 9 && i <= X; i++)
    {
      // for each iteration's number, start a graph for BFS traversal finding jumping numbers. For eg, for 2 -> 21, 23, 210, 212, 232, 234 .... so on
      bfs(max, X, i);
    }
    return max;
  }

private:
  // BFS Traversal function
  void bfs(long long &maximum, long long x, int i)
  {
    // make a queue and push the root inside it
    queue<long long> q;
    q.push(i);

    // start popping the items from the inside of the queue
    while (!q.empty())
    {
      long long front = q.front();
      q.pop();

      // if the popped element is less than x, it can be considered, and its possible children can be pushed into queue
      if (front <= x)
      {
        maximum = max(maximum, front);

        // get the last digit
        long long lastDigit = front % 10;

        if (lastDigit == 0)
        {
          // 0 -> 01
          q.push(front * 10 + 1);
        }
        else if (lastDigit == 9)
        {
          // 9 -> 98
          q.push(front * 10 + 8);
        }
        else if (lastDigit >= 1 && lastDigit <= 8)
        {
          // Lets say we popped 1 -> push into queue 10 and 12
          q.push(front * 10 + lastDigit + 1);
          q.push(front * 10 + lastDigit - 1);
        }
      }
    }
  }
};

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    long long X;

    cin >> X;

    Solution ob;
    cout << ob.jumpingNums(X) << endl;
  }
  return 0;
}