// Program to Binary Search in a rotated Array
// i.e instead of 1,2,3,4 -> 3,4,1,2 example
// https://www.youtube.com/watch?v=QdVrY3stDD4

#include<iostream>

using namespace std; 

int binarySearch(int arr[], int n, int key) {

    // Find the smallest element in the array and make it our pivot
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int middle = (left + right) / 2;    // find the middle
        if (arr[middle] > arr[right]) {
            // means the smallest element lies to the right of middle
            left = middle + 1;
        } else
            // means the smallest lies either eql to or on the left of middle
            right = middle;
    }
    // left always ends up with minimum value
    // now that we have the middle element, just use a modified binnary search

    /*
    *   You can also use these statements to find the least valued index
    * 
    *   
        int val = INT_MAX;
	    for(int i = 0; i < n ;i++)
	    {
		    if(arr[i]<val)
		    {
			    left=i;	
		    }
	    }
    *
    */

    int start = left;
    left = 0;
    right = n - 1;

    // define your search zone i.e ahead of lowest val or before the lowest val
    if (key >= arr[start] && key <= arr[right])
        left = start;
    else
        right = start - 1;

    // normal binary search
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == key)
            return middle;
        else if (arr[middle] > key)
            right = middle - 1;
        else
            left = middle + 1;
    }
    return -1;
}


int main() {
    int n;
    cout << "Input the random array size :";
    cin >> n;
    int arr[n];

    // input the array
    cout << "Enter the elements of rotated array:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // input the key to be found
    int key;
    cout<<"Enter the key:";
    cin >> key;

    // main funciton
    int ans = binarySearch(arr, n, key);

    // Output
    if (ans == -1)
        cout << "Element not present" << endl;
    else
        cout << "Element found at position " << ans+1 << endl;


    return 0;
}