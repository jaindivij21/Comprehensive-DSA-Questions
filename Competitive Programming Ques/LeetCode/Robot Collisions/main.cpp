// Leetcode: Robot Collisions
// https://leetcode.com/problems/robot-collisions

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <vector>

using namespace std;

class Robot
{
public:
  bool direction; // true for 'R', false for 'L'
  int position;   // store original position
  int health;     // store current health

  // Constructor
  Robot(int position, int health, bool direction) : position(position), health(health), direction(direction) {}

  // Static method to create and sort robots based on their positions
  static vector<Robot> create(const vector<int> &positions, const vector<int> &healths, const string &directions)
  {
    vector<Robot> robots;
    for (int i = 0; i < positions.size(); i++)
    {
      Robot temp(positions[i], healths[i], directions[i] == 'R');
      robots.push_back(temp);
    }
    sortRobots(robots);
    return robots;
  }

  // Static method to sort robots based on their positions
  static void sortRobots(vector<Robot> &robots)
  {
    sort(robots.begin(), robots.end(), comparator);
  }

  // Comparator function to sort robots by position
  static bool comparator(Robot a, Robot b)
  {
    return a.position < b.position;
  }
};

vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string &directions)
{
  // Create and sort robots
  vector<Robot> robots = Robot::create(positions, healths, directions);

  // Stack to keep track of robots that are currently in the line
  stack<Robot> robotStack;

  // Process each robot
  for (auto &robot : robots)
  {
    // If stack is empty, directions are the same, or both are moving left, push to stack
    if (robotStack.empty() || robotStack.top().direction == robot.direction || !robotStack.top().direction)
    {
      robotStack.push(robot);
    }
    else
    {
      // Handle collisions
      while (!robotStack.empty() && robotStack.top().direction != robot.direction)
      {
        Robot topRobot = robotStack.top();
        if (topRobot.health == robot.health)
        {
          // Both robots have the same health, remove both
          robotStack.pop();
          robot.health = 0;
          break;
        }
        else if (topRobot.health > robot.health)
        {
          // Top robot has more health, decrement its health and remove the current robot
          robotStack.pop();
          robot.health = 0;
          topRobot.health -= 1;
          robotStack.push(topRobot);
          break;
        }
        else
        {
          // Current robot has more health, decrement its health and remove the top robot
          robotStack.pop();
          robot.health -= 1;
        }
      }
      // If the current robot still has health left, push it to the stack
      if (robot.health > 0)
      {
        robotStack.push(robot);
      }
    }
  }

  // Map to store the surviving robots' health by their position
  unordered_map<int, int> positionToHealthMap;
  while (!robotStack.empty())
  {
    Robot survivingRobot = robotStack.top();
    robotStack.pop();
    positionToHealthMap[survivingRobot.position] = survivingRobot.health;
  }

  // Prepare the result based on the original positions
  vector<int> result;
  for (int position : positions)
  {
    if (positionToHealthMap.find(position) != positionToHealthMap.end() && positionToHealthMap[position] > 0)
    {
      result.push_back(positionToHealthMap[position]);
    }
  }

  return result;
}

int main()
{
  vector<int> positions = {34, 50, 42, 2};
  vector<int> healths = {6, 27, 17, 38};
  string directions = "LLRR";

  vector<int> result = survivedRobotsHealths(positions, healths, directions);

  // Output the result
  for (int health : result)
  {
    cout << health << " ";
  }

  return 0;
}