// Leetcode: Asteroid Collision
// https://leetcode.com/problems/asteroid-collision

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
  vector<int> asteroidCollision(vector<int> &asteroids)
  {
    stack<int> asteroidStack; // Stack to simulate asteroid collisions

    for (int i = 0; i < asteroids.size(); i++)
    {
      int currentAsteroid = asteroids[i];

      // If the stack is empty or no collision scenario exists, push the asteroid
      if (asteroidStack.empty() || !(asteroidStack.top() > 0 && currentAsteroid < 0))
      {
        asteroidStack.push(currentAsteroid);
      }
      else
      {
        // Collision scenario: asteroid moving left meets one moving right
        int topAsteroid = asteroidStack.top();

        int topAsteroidSize = abs(topAsteroid);
        int currentAsteroidSize = abs(currentAsteroid);

        if (topAsteroidSize == currentAsteroidSize)
        {
          // Both asteroids are the same size; both explode
          asteroidStack.pop();
        }
        else if (topAsteroidSize > currentAsteroidSize)
        {
          // Top asteroid is larger; current asteroid explodes (do nothing)
        }
        else
        {
          // Current asteroid is larger; top asteroid explodes
          asteroidStack.pop();
          i--; // Reprocess the current asteroid
        }
      }
    }

    // Prepare the result by transferring elements from the stack to a vector
    vector<int> remainingAsteroids;
    while (!asteroidStack.empty())
    {
      remainingAsteroids.push_back(asteroidStack.top());
      asteroidStack.pop();
    }

    // Reverse the vector to maintain original order
    reverse(remainingAsteroids.begin(), remainingAsteroids.end());

    return remainingAsteroids;
  }
};

int main()
{
  Solution sol;
  vector<int> asteroids = {5, 10, -5};

  vector<int> ans = sol.asteroidCollision(asteroids);

  return 0;
}