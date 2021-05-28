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
    up = arr[n - 1];
    low = arr[0];

    while (low <= up) {
        mid = (up + low) / 2;
        cows=0;
        // code to place the cows
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                cows++;
                pointer = arr[i];
            } else {
                gap = arr[i] - pointer;
                if (gap >= mid) {
                    cows++;
                    pointer = arr[i];
                } else
                    continue;
            }
        }

        if (cows >= c) {
            best = mid;
            low = mid + 1;
        } else
            up = mid - 1;
    }

    cout<<best;

    return 0;
}
