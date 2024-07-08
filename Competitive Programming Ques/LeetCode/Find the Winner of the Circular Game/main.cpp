// Leetcode: Find the Winner of the Circular Game
// https://leetcode.com/problems/find-the-winner-of-the-circular-game

#include <iostream>
#include <queue>

using namespace std;

// Function to find the winner of the circular game
int findTheWinner(int numberOfFriends, int stepCount)
{
  // Create a queue to store the friends in the circle
  queue<int> friendsQueue;

  // Initialize the queue with friends numbered from 1 to numberOfFriends
  for (int i = 1; i <= numberOfFriends; i++)
    friendsQueue.push(i);

  // Variable to keep track of the count
  int currentStep = 0;

  // Continue the process until only one friend remains in the circle
  while (friendsQueue.size() != 1)
  {
    currentStep++;
    int currentFriend = friendsQueue.front(); // Get the friend at the front of the queue

    // If the current step is less than stepCount, push the current friend to the back of the queue
    if (currentStep < stepCount)
    {
      friendsQueue.push(currentFriend);
    }
    else
    {
      // Reset the step count when it reaches stepCount and the friend at the front is removed
      currentStep = 0;
    }

    // Remove the current friend from the queue
    friendsQueue.pop();
  }

  // The last remaining friend is the winner
  return friendsQueue.front();
}

int main()
{
  int numberOfFriends, stepCount;

  // Take input for the number of friends and the integer stepCount
  cin >> numberOfFriends >> stepCount;

  // Output the winner of the game
  cout << findTheWinner(numberOfFriends, stepCount) << endl;

  return 0;
}
