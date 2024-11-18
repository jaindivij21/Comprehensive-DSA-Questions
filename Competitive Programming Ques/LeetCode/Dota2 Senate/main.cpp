// Leetcode: Dota2 Senate
// https://leetcode.com/problems/dota2-senate

#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
  string predictPartyVictory(string senate)
  {
    queue<int> radiantQueue; // Queue to store indices of Radiant senators
    queue<int> direQueue;    // Queue to store indices of Dire senators

    // Populate both queues with the indices of 'R' (Radiant) and 'D' (Dire) senators
    for (int i = 0; i < senate.size(); i++)
    {
      if (senate[i] == 'R')
      {
        radiantQueue.push(i);
      }
      else
      {
        direQueue.push(i);
      }
    }

    // Total number of senators: For travelling rounds circularly
    int totalSenators = senate.size();

    // Continue the process until one of the queues is empty
    // A senator from one party will banish a senator from the other party
    while (!radiantQueue.empty() && !direQueue.empty())
    {
      int radiantIndex = radiantQueue.front();
      int direIndex = direQueue.front();

      // The senator with the smaller index gets to banish the senator with the larger index
      if (radiantIndex < direIndex)
      {
        radiantQueue.push(totalSenators); // Radiant senator gets a new turn (adds to the end of the queue)
      }
      else
      {
        direQueue.push(totalSenators); // Dire senator gets a new turn (adds to the end of the queue)
      }

      // Pop the front elements (those who were banished)
      radiantQueue.pop();
      direQueue.pop();

      totalSenators++; // Increase the total number of senators as a new senator will be added
    }

    // If the Radiant queue is empty, Dire wins, otherwise Radiant wins
    return radiantQueue.empty() ? "Dire" : "Radiant";
  }
};

int main()
{
  Solution s;
  string str = "RDD";

  cout << s.predictPartyVictory(str) << endl;

  return 0;
}