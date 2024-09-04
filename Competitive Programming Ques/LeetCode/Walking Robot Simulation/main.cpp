// Leetcode: Walking Robot Simulation
// https://leetcode.com/problems/walking-robot-simulation

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
  enum Direction
  {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
  };

  // Variables
  pair<int, int> currentPosition = {0, 0};
  enum Direction currentDirection = Direction::NORTH;
  unordered_set<string> obstacles;

  // Methods
  int robotSim(vector<int> &commands, vector<vector<int>> &obs)
  {
    setObstacles(obs);

    int maxEuclideanDistance = INT_MIN;
    for (auto command : commands)
    {
      Solution::move(command);
      maxEuclideanDistance = max(
          maxEuclideanDistance,
          currentPosition.first * currentPosition.first + currentPosition.second * currentPosition.second);
    }
    return maxEuclideanDistance;
  }

private:
  void move(int command)
  {
    switch (command)
    {
    case -1:
      currentDirection = static_cast<Direction>((currentDirection + 1) % 4);
      break;
    case -2:
      currentDirection = static_cast<Direction>((currentDirection + 3) % 4);
      break;
    default:
      int steps = command;

      for (int i = 0; i < steps; i++)
      {
        pair<int, int> nextPosition;

        switch (currentDirection)
        {
        case Direction::NORTH:
          nextPosition = {currentPosition.first, currentPosition.second + 1};
          break;
        case Direction::SOUTH:
          nextPosition = {currentPosition.first, currentPosition.second - 1};
          break;
        case Direction::EAST:
          nextPosition = {currentPosition.first + 1, currentPosition.second};
          break;
        case Direction::WEST:
          nextPosition = {currentPosition.first - 1, currentPosition.second};
          break;
        }

        string encodedPosition = encodeCoordinate(nextPosition.first, nextPosition.second);
        if (obstacles.find(encodedPosition) == obstacles.end())
        {
          currentPosition = nextPosition;
        }
        else
        {
          break;
        }
      }
    }
  }

  void setObstacles(vector<vector<int>> &obs)
  {
    for (auto &obstacle : obs)
    {
      obstacles.insert(encodeCoordinate(obstacle[0], obstacle[1]));
    }
  }

  static string encodeCoordinate(int x, int y)
  {
    return to_string(x) + "_" + to_string(y);
  }
};

int main()
{
  Solution solution;
  vector<int> commands = {4, -1, 3};
  vector<vector<int>> obstacles = {};
  cout << solution.robotSim(commands, obstacles) << endl;

  return 0;
}