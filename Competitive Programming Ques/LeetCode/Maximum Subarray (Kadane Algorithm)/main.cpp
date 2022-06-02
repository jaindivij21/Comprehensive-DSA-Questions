// Maximum Subarray : Leetcode
// https://leetcode.com/problems/maximum-subarray/

// Kadane's Algorithm

#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> const v)
{
    int finalAns = v[0];
    int largest = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        if (largest + v[i] > v[i])
        {
            largest += v[i];
        }
        else
        {
            largest = v[i];
        }
        finalAns = max(finalAns, largest);
    }
    return finalAns;
}

int main()
{
    int size;
    cin >> size;

    vector<int> v;
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    cout << maxSubArray(v);

    return 0;
}

// Naive Solution : Brute Force

// int maxSubArray(vector<int>& nums) {
//     int maxSum = INT_MIN;
//     for(int i = 0; i < nums.size(); i++){
//         for(int j = i; j < nums.size(); j++){
// we have the end points of the array
// so cal the current sum using the subarray
//             int currSum = 0;
//             for(int k = i; k <= j; k++){
//                 currSum += nums[k];
//             }
//             maxSum = max(currSum, maxSum);
//         }
//     }
//     return maxSum;
// }