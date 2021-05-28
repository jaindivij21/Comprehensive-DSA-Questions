// Inversion count
// In an array count all the pairs where: a[i] > a[j] but i < j. Which means: all such pairs where larger elements occur behind smaller elements!
// Example: 1 3 2 : one pair of inversion: (3,2) since 3>2 but its index is smaller than that of 2 i.e it comes before 2.

// CONCEPT: Same concept to be used as that of merge sort. Only difference is to keep a count pointer that (Divide adn Conquer)
// https://www.geeksforgeeks.org/counting-inversions/
// https://www.youtube.com/watch?v=sV4RhDIIKO0

#include<iostream>

using namespace std;

// merge function (this also counts no of inversions  that take place after merging)
int merge(int *a, int s, int e) {
    int mid = (s + e) / 2;

    // use the concept of merging to merge both the subarrays
    int i = s;
    int j = mid + 1;
    int k = s;

    // take a temporary array in which you'll store the merged array
    int temp[100000];

    // cross inversions count
    int count = 0;

    // main comparisons
    while (i <= mid && j <= e) {
        if (a[i] <= a[j]) {
            // no issue to increment count since no inversion
            temp[k++] = a[i++];
        } else {
            // case when cross inversion occurs
            temp[k++] = a[j++];
            count += (mid - i + 1);
        }
    }

    // fill the array if some elements are left in one of the arrays
    for (; i <= mid; i++)
        temp[k++] = a[i];
    for (; j <= e; j++)
        temp[k++] = a[j];

    // copy all element back from temp to array
    for (int m = s; m <= e; m++)
        a[m] = temp[m];

    return count;
}


// main function (Inversion Count)
int inversionCount(int a[], int s, int e) {
    // base case (This also covers the case when array len is 0 or 1)
    if (s >= e)
        return 0;

    // calculate mid
    int mid = (s + e) / 2;

    // recursion
    int x = inversionCount(a, s, mid);
    int y = inversionCount(a, mid + 1, e);    // assume that they are correct
    int z = merge(a, s, e);
    // x and y will contain the inversions in the subarrays
    // z it will contain the inversions count that happened when we merge those 2 subarrays with x and y inversions respectively

    return x + y + z;   // total number of count inversions
}


int main() {

    // input the array
    int a[100];

    cout << "Enter the size" << endl;
    int n;
    cin >> n;

    cout << "Enter the array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // main function
    cout << "Inversion Count: " << inversionCount(a, 0, n - 1) << endl;
}