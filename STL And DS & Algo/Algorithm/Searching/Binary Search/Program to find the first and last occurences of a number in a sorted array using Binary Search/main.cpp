// Program to find out the first and last occurences of elements in an array
// To be done using binary search and mind it that the array must be sorted
// eg. 1,2,3,4,5,6,8,8,8,8,8,8,10 -  6th & 11th index for '8'

#include<iostream>
#include<algorithm>

using namespace std;

int binarySearch(int arr[], int n, int key, bool flag) {
    int left = 0;
    int right = n - 1;
    int ans = 0;
    int temp = 0;
    int mid;
    while (left <= right) {
        // only find the middle element if key hasnt yet been found
        if(temp == 0)
            mid = (left + right) / 2;
        // if key is found & is the middle element
        if (arr[mid] == key) {
            ans = mid;  // ans --> mid
            {
                // if left has to be found decrement value of mid and set key as found (to avoid new mid's calculation in first line of loop)
                // if right has to be found increment value of mid and set key as found (to avoid new mid's calculation in first line of loop)
                !flag ? (mid--) : (mid++);
                temp = 1;
            }
        }
        // if key is before the middle element 
        else if (arr[mid] > key) {
            right = mid - 1;    // update the right
            // if key's left most occurence has been already found, return the index
            if (temp == 1) {
                return ans;
            }
        } 
        // if key is after the middle element 
        else {
            left = mid + 1; // update the left
            // if key's right most occurence has been already found, return the index
            if (temp == 1) {
                return ans;
            }
        }
    }
    return -1;
}

int main() {
    // input the size and the array
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // input the key whose first and last position has to be acquired
    int key;
    cin >> key;

    // Print the results
    cout << "The left most occurence of " << key << " is " << binarySearch(arr, size, key, false) << endl;
    cout << "The right most occurence of " << key << " is " << binarySearch(arr, size, key, true) << endl;
    return 0;
}