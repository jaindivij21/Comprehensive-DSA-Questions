// Leetcode: Water Bottles
// https://leetcode.com/problems/water-bottles

#include <iostream>

using namespace std;

// Function to recursively calculate the maximum number of water bottles drinkable
int recursiveHelperFx(int filledBottles, int emptyBottles, int numExchange)
{
  // Base Case: If we can no longer exchange enough bottles to get a new bottle
  if (filledBottles + emptyBottles < numExchange)
  {
    return filledBottles; // Return the number of bottles drank so far
  }

  // Recursive Case: Calculate new filled and empty bottles after exchange
  return filledBottles + recursiveHelperFx(
                             (filledBottles + emptyBottles) / numExchange,
                             (filledBottles + emptyBottles) % numExchange,
                             numExchange);
}

// Function to calculate the maximum number of water bottles drinkable
int numWaterBottles(int numBottles, int numExchange)
{
  return recursiveHelperFx(numBottles, 0, numExchange); // Start recursion with initial bottles
}

int main()
{
  int numBottles, numExchange;
  cin >> numBottles >> numExchange;

  cout << numWaterBottles(numBottles, numExchange) << endl;

  return 0;
}