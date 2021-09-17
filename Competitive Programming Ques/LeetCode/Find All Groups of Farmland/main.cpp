// Leecode : Find all groups of Farmland
// https://leetcode.com/problems/find-all-groups-of-farmland/

// Time Complexity : O(n2)

// Can be solved using depth first search but the directions needed for the search is only right and bottom direction

#include <bits/stdc++.h>

using namespace std;

// dfs function : recursive (the main catch is the dfs propagation must just be in the right and bottom direction
void dfs(vector<vector<int>> &land, vector<int> &temp, int m, int n)
{
    // base case
    // if outside the boundary: simply return
    if (m < 0 || m >= land.size() || n < 0 || n >= land[0].size())
        return;
    if (land[m][n] != 1)
        return;

    land[m][n] = -1; // mark visited

    // recursive cases : towards right and bottom
    dfs(land, temp, m, n + 1);
    dfs(land, temp, m + 1, n);
    if (temp.size() != 4)
    {
        temp.push_back(m);
        temp.push_back(n);
    }
}

// main function
vector<vector<int>> findFarmland(vector<vector<int>> &land)
{
    vector<vector<int>> ans; // stores the answer

    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land[0].size(); j++)
        {
            // traverse over the entire land
            if (land[i][j] == 1)
            {
                // unvisited farm land
                vector<int> temp; // stores the temp ans
                temp.push_back(i);
                temp.push_back(j);
                dfs(land, temp, i, j);
                ans.push_back(temp);
            }
            else
            {
                // means it's either a forestland or already visited farmland
                continue;
            }
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> land = {{1, 0, 0},
                                {0, 1, 1},
                                {0, 1, 1}};
    vector<vector<int>> ans = findFarmland(land);
}