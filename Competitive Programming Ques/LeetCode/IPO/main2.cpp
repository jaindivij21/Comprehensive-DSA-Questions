// Leetcode: IPO
// https://leetcode.com/problems/ipo/description/
// https://www.youtube.com/watch?v=asSjKWgzx00

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
{
  // Create a vector of pairs to store capital and profits
  vector<pair<int, int>> projects(profits.size());

  // Populate the vector with project data
  for (int i = 0; i < profits.size(); i++)
  {
    projects[i] = {capital[i], profits[i]};
  }

  // Sort projects based on minimum capital required
  sort(projects.begin(), projects.end(), [](pair<int, int> a, pair<int, int> b)
       { return a.first < b.first; });

  // Define a max heap to store profits
  priority_queue<int> maxProfitHeap;
  int projectIndex = 0;

  // Execute until all projects are considered or k projects are chosen
  while (k--)
  {
    // Add affordable projects to the heap
    while (projectIndex < projects.size() && projects[projectIndex].first <= w)
    {
      maxProfitHeap.push(projects[projectIndex].second);
      projectIndex++;
    }

    // If no affordable projects or budget constraint met, exit loop
    if (maxProfitHeap.empty())
      break;

    // Pick the project with maximum profit under budget constraint
    int maxProfit = maxProfitHeap.top();
    maxProfitHeap.pop();
    w += maxProfit; // Increase capital
  }

  // Return the final maximized capital
  return w;
}

int main()
{
  int k = 2;
  int w = 0;
  vector<int> profits = {1, 2, 3};
  vector<int> capital = {0, 1, 1};

  cout << findMaximizedCapital(k, w, profits, capital) << endl;

  return 0;
}