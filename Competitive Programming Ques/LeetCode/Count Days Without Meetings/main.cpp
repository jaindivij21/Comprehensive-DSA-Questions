// Leetcode: Count Days Without Meetings
// https://leetcode.com/problems/count-days-without-meetings

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
   public:
    int countDays(int days, vector<vector<int> > &meetings)
    {
        // Sort meetings based on the starting day
        ranges::sort(meetings, [](vector<int> &a, vector<int> &b)
                     { return a[0] < b[0]; });

        // Index for iterating through meetings
        int i = 0;

        // First Meeting
        int freeDays = meetings[i][0] - 1;
        int lastMaxDay = meetings[i][1];

        i++;

        // Iterate through the sorted middle meetings
        for (; i < meetings.size(); i++)
        {
            if (meetings[i][0] <= lastMaxDay)
            {
                lastMaxDay = max(lastMaxDay, meetings[i][1]);
                continue;
            }
            freeDays += (meetings[i][0] - lastMaxDay - 1);
            lastMaxDay = meetings[i][1];
        }

        // Last meeting
        freeDays += (days - lastMaxDay);

        return freeDays;
    }
};

int main()
{
    Solution solution;
    int days = 10;
    vector<vector<int> > meetings = {{2, 3}, {5, 6}, {3, 4}, {8, 9}};

    cout << solution.countDays(days, meetings) << endl;  // Output: 2

    return 0;
}
