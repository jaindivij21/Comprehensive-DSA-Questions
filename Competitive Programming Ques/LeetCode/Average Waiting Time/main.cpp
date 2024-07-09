// Leetcode: Average Waiting Time
// https://leetcode.com/problems/average-waiting-time/

#include <iostream>
#include <vector>

using namespace std;

// Simulation Brute Force Problem
double averageWaitingTime(vector<vector<int>> &customers)
{
  // Tracks the current time
  int currentTime = 0;
  // Sum of all customers' waiting times
  double totalWaitingTime = 0;

  for (const auto &customer : customers)
  {
    int arrivalTime = customer[0];
    int cookingTime = customer[1];

    // If the chef is idle when the customer arrives, start cooking immediately
    if (currentTime < arrivalTime)
    {
      currentTime = arrivalTime;
    }

    // The chef starts cooking the current order and updates the current time
    currentTime += cookingTime;

    // Calculate the waiting time for the current customer and add it to the total
    totalWaitingTime += (currentTime - arrivalTime);
  }

  // Return the average waiting time
  return totalWaitingTime / customers.size();
}

int main()
{
  vector<vector<int>> customers = {{1, 2},
                                   {2, 5},
                                   {4, 3}};

  cout << averageWaitingTime(customers) << endl;
  return 0;
}
