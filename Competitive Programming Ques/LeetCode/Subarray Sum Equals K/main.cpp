// Subarray sum equal to K :: Leetcode
// https://leetcode.com/problems/subarray-sum-equals-k/

// we have to return the total number of subarrays that sum up to K

// Sliding Window Problem (Cumulative sum and hash map)

#include<bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> const &nums, int k) {
    // cal the cum sum
    unordered_map<int, int> cumSum; //  cumulative sum and its count
    // indicates the start of the array
    cumSum.insert(make_pair(0, 1));

    int count = 0;
    int sum = 0;
    // we now have the cumulative sum map
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        int num = sum;
        int difference = num - k;

        if (cumSum.find(difference) != cumSum.end()) {
            count += cumSum[difference];
        }
        if (cumSum.find(sum) == cumSum.end())
            cumSum.insert(make_pair(sum, 1));
        else
            cumSum[sum]++;
    }
    return count;
}

int main() {
    int size;
    cin >> size;
    int k;
    cin >> k;
    vector<int> v;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << subarraySum(v, k);
    return 0;
}