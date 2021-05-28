// Quick Sort (Like Merge Sort its, divide and conquer)
// https://www.geeksforgeeks.org/quick-sort/
// https://www.youtube.com/watch?v=PgBzjlCcFvc&feature=emb_title

// O(NlogN) but worst case is O(N2)
// QuickSort is Inplace Sort Algorithm

#include<iostream>

using namespace std;

// the partition function
// returns the index of pivot after correct partition
int partition(int a[], int s, int e) {
    // select the last element as pivot element
    int pivot = a[e];
    int i = s - 1;  // no smaller region initially
    int j = s;

    for (; j <= e - 1;) {
        if (a[j] <= pivot) {
            // merge the smaller element in the region - 1
            i = i + 1;
            swap(a[i], a[j]);
        } // remember j is getting incrememnted everytime
        j++;
    }
    swap(a[i + 1], a[e]);
    return i + 1;
}


// main function
void quickSort(int a[], int s, int e) {
    // base case
    if (s >= e) // smallest array is with len 0 or 1, it'll already be sorted
        return;
    else {
        // recurisve part
        // partition the array into subarray based on a pivot element
        int p = partition(a, s, e);
        // apply recursive quick sort on left and right part of the array
        quickSort(a, s, p - 1);
        quickSort(a, p + 1, e);
    }
}

int main() {

    // input the array
    cout << "Enter the size" << endl;
    int n;
    cin >> n;

    int a[n];

    cout << "Enter the array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // main function
    quickSort(a, 0, n - 1);

    cout << "Sorted Array:" << endl;
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}