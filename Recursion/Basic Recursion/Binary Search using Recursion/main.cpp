// Program for bianry search using recursion

#include<iostream>

using namespace std;

// binary search recursive function
int binarySearch(int arr[], int l, int r, int element) {
    // the array needs to be sorted for this to execute

    // outer condn
    if (l <= r) {
        int mid = (l + r) / 2;

        // base case
        if (arr[mid] == element)
            return mid; // mid element is our search element
            // recursive calls (there will be 2 of them)
        else if (element > arr[mid]) {
            // mid element is less than our search element
            return binarySearch(arr, mid + 1, r, element);
        } else {
            // mid element is greater than our search element
            return binarySearch(arr, l, mid - 1, element);
        }

    } else {
        // element not found
        return -1;
    }
}


int main() {
    // input the array
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // element to be searched
    int x;
    cin >> x;

    // main part
    // initial conds
    int l = 0;
    int r = size - 1;
    int ans = binarySearch(arr, l, r, x);
    if (ans == -1)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index: " << ans << endl;

    return 0;
}
