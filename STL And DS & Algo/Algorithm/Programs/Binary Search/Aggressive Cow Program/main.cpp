// AGGRESSIVE COW PROBLEM
// https://www.spoj.com/problems/AGGRCOW/
// program to find the maximum distance bw the cows in barn such that all cows are accomodated
// Solving using Binary Search

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // get the inputs
    int n, c;
    cout << "Enter the number of stalls such that (n>=2):";
    cin >> n;
    cout << "Enter the number of cows such that (c<=n):";
    cin >> c;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // sort the array
    sort(arr, arr + n);

    // declaring necessary values
    int low, up, pointer, mid, cows = 0, gap, best;
    up = arr[n - 1];    // contains the last value of array
    low = arr[0];   // contains the first value

    // binary search technique
    while (low <= up) {
        mid = low + (up - low) / 2; // cal the mid value (to be taken as gap)
        cows = 0;
        
        // code to place the cows

        // for every index
        for (int i = 0; i < n; i++) {
            // place the first cow on first index(i=0)
            if (i == 0) {
                cows++;
                pointer = arr[i];   // assign pointer as that value (helps to cal gap)
            } else {
                // else cal gap and if its more or eql to mid, place the element otherwise continue to next index
                gap = arr[i] - pointer;
                if (gap >= mid) {
                    cows++;
                    pointer = arr[i];
                } else
                    continue;
            }
        }

        // if number of cows placed are more than or eql to given cows, we'll try to increase the gap and reiterate the problem
        if (cows >= c) {
            best = mid;
            low = mid + 1;
        } else  // else we'll try with reduced gap therefore change the up value
            up = mid - 1;
    }

    cout << best;

    return 0;
}
