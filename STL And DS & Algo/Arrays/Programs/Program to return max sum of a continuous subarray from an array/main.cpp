// Program to return the max sum of a continuous subarray from an array
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
// *********** KADANE'S ALGORITHM *******************

#include<iostream>
#include<algorithm>
using namespace std;

void calSum(int arr[], int size)
{
    int maxSum = arr[0];
    int currSum = maxSum;
    for(int i = 1; i<size; i++)
    {
        currSum = max(arr[i], currSum+arr[i]);
        maxSum = max(currSum, maxSum);
    }
    cout<<maxSum<<endl;
}

int main()
{
    int testCases;
    cin>>testCases;

    while(testCases--)
    {
        int size;
        cin>>size;
        int arr[size];
        // input array
        for(int i = 0; i<size; i++)
            cin>>arr[i];

        // main part
        calSum(arr, size);
    }

    return 0;
}