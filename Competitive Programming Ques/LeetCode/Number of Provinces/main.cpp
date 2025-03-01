// Leetcode: Number of Provinces
// https://leetcode.com/problems/number-of-provinces

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    // Function to find the number of provinces: Essentially the number of
    // connected components
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        if (isConnected.size() == 1) return true;

        vector<vector<int>> adjList = getAdjList(isConnected);
        isConnected.clear();

        vector<bool> visitedCities(adjList.size(), false);
        int noOfProvinces = 0;

        for (int i = 0; i < adjList.size(); i++)
        {
            if (!visitedCities[i])
            {
                noOfProvinces++;

                dfs(adjList, visitedCities, i);
            }
        }

        return noOfProvinces;
    }

   private:
    vector<vector<int>> getAdjList(vector<vector<int>> &adjMatrix)
    {
        int n = adjMatrix.size();
        vector<vector<int>> adjList(n);

        for (int i = 0; i <= n - 2; i++)
        {
            for (int j = i + 1; j <= n - 1; j++)
            {
                if (adjMatrix[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        return adjList;
    }

    void dfs(vector<vector<int>> &adjList, vector<bool> &visitedCities, int i)
    {
        // Base Case
        if (visitedCities[i]) return;

        // Recursive Cases
        visitedCities[i] = true;
        for (auto &city : adjList[i]) dfs(adjList, visitedCities, city);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> adjMatrix = {
        {1, 0, 0, 1}, {0, 1, 1, 0}, {0, 1, 1, 1}, {1, 0, 1, 1}};

    cout << "Number of provinces: " << s.findCircleNum(adjMatrix) << endl;

    return 0;
}