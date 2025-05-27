// Leetcode: Top K Frequent Elements
// https://leetcode.com/problems/top-k-frequent-elements

#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
   public:
    static vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqCount;
        for (int num : nums)
        {
            freqCount[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int> >,
                       greater<pair<int, int> > >
            minHeap;

        for (auto &entry : freqCount)
        {
            minHeap.push({entry.second, entry.first});
            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        vector<int> result;
        while (!minHeap.empty())
        {
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    constexpr int k = 2;

    Solution::topKFrequent(nums, k);

    return 0;
}
