// Program to to find the pivot element in a sorted array
// Basically find the largest element
// To do using binary -> dont do it linearly

#include<iostream>
#include<algorithm>

using namespace std;

int findPivot(int n, int arr[]) {
    // using bianry search
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = (s + e) / 2;

        // since its sorted,
        // if mid-1 is more than mid
        if (arr[mid - 1] > arr[mid])
            return mid - 1;
        // if mid is more than mid+1
        else if (arr[mid] > arr[mid + 1])
            return mid;
        // else check if pivot is on the right of mid or left of mid
        else {
            // left since left of mid is unsorted
            if (arr[s] > arr[mid])
                e = mid - 1;
            // right since right of mid is unsorted
            else
                s = mid + 1;
        }
    }
    // if not found return -1
    return -1;
}


int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findPivot(n, arr) << endl;
    return 0;;
}