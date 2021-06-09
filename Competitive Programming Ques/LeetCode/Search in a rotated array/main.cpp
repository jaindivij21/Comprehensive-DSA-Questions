// Search in a rotated array :: Leetcode
// https://leetcode.com/problems/search-in-rotated-sorted-array/

// Binary Search

#include<bits/stdc++.h>

using namespace std;

int search(vector<int> &arr, int tar) {
    // find the starting index (to make it behave like a sorted array)
    int left = 0;
    int right = arr.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] > arr[right]) {
            // peculiar behaviour :: element that comes before is bigger
            left = mid + 1;
        } else {
            // element that comes before may be equal or smaller
            right = mid;
        }
    }

    // after this loop the left variable will store the starting index of the smallest element
    int start = left;
    left = 0;
    right = arr.size() - 1;

    // shorten the window to make it sorted
    if (tar >= arr[start] && tar <= arr[right])
        left = start;
    else
        right = start - 1;

    // now apply normal binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == tar) {
            return mid;
        } else if (arr[mid] > tar) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    int size;
    cin >> size;

    vector<int> arr;
    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    int target;
    cin >> target;

    cout << search(arr, target);

    return 0;
}