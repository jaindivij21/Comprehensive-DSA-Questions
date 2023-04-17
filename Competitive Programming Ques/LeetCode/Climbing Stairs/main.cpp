// Leetcode: Climbing Stairs
// https://leetcode.com/problems/climbing-stairs/

#include <iostream>
#include <unordered_map>

using namespace std;

// Dynamic Programming : Memorization (Bottom Up Approach)
unordered_map<int, int> steps;

// Helper Method
int helper(int &stairs, int currentStep)
{
  // base cases
  if (currentStep == stairs)
  {
    return 1;
  }
  else if (currentStep > stairs)
  {
    return 0;
  }
  else if (steps.find(currentStep) != steps.end())
  {
    return steps[currentStep];
  }
  else
  {
    // recursive case
    int waysWithOneJump = helper(stairs, currentStep + 1); // One Jump
    int waysWithTwoJump = helper(stairs, currentStep + 2); // Two Jumps
    steps[currentStep] = waysWithOneJump + waysWithTwoJump;
    return steps[currentStep];
  }
}

// Main method
int climbStairs(int n)
{
  int currentStep = 0;
  return helper(n, currentStep);
}

int main()
{
  cout << climbStairs(3) << endl;

  return 0;
}