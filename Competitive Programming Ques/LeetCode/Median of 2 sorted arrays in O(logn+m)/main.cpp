// Median of two sorted arrays :: Leetcode
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// https://youtu.be/yD7wV8SyPrc

#include<bits/stdc++.h>

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    //we want to partition nums1 and nums2 at some point x and y such that 
    //the sum of number of elements to left of x and y is equal to the right
    if (nums1.size() < nums2.size())
        return findMedian(nums1, nums2);
    return findMedian(nums2, nums1);
}

double findMedian(vector<int> arr1, vector<int> arr2) {
    int len1 = arr1.size();
    int len2 = arr2.size();
    int low = 0;
    int high = len1;
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (len1 + len2 + 1) / 2 - partitionX;
        
        //now find the maxleftx and maxlefty and check whether thet are less than minRighty and minRightX respectively
        int maxLeftX = (partitionX == 0) ? (INT_MIN) : arr1[partitionX - 1];
        int minRightX = (partitionX == len1) ? (INT_MAX) : arr1[partitionX];

        int maxLeftY = (partitionY == 0) ? (INT_MIN) : arr2[partitionY - 1];
        int minRightY = (partitionY == len2) ? (INT_MAX) : arr2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            double res;
            if ((len1 + len2) % 2 == 0) {
                res = double((max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / double(2));
            } else {
                res = max(maxLeftX, maxLeftY);
            }
            return res;
        } else if (maxLeftX > minRightY) {
            //we need to move the partitionX to left
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    return 0;
}
