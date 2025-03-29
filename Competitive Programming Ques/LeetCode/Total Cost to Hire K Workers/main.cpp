// Leetcode: Total Cost to Hire K Workers
// https://leetcode.com/problems/total-cost-to-hire-k-workers

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define pp pair<int, int>

struct Compare
{
    bool operator()(const pp &a, const pp &b) const
    {
        if (a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};

class Solution
{
   public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        const int costsSize = costs.size();
        priority_queue<pp, vector<pp>, Compare> minHeap;  // (Cost, Index)

        int i = 0, j = costsSize - 1;

        while (candidates-- && i <= j)
        {
            minHeap.emplace(costs[i], i++);
            if (i <= j) minHeap.emplace(costs[j], j--);
        }

        long long totalCost = 0;

        while (k--)
        {
            auto [cost, idx] = minHeap.top();
            minHeap.pop();
            totalCost += cost;

            if (i <= j)
            {
                if (idx < i)
                {
                    minHeap.emplace(costs[i], i++);
                }
                else
                {
                    minHeap.emplace(costs[j], j--);
                }
            }
        }

        return totalCost;
    }
};

int main()
{
    Solution solution;
    vector<int> costs = {17, 12, 10, 2, 7, 2, 11, 20, 8};
    constexpr int k = 3, candidates = 4;

    cout << solution.totalCost(costs, k, candidates) << endl;

    return 0;
}
