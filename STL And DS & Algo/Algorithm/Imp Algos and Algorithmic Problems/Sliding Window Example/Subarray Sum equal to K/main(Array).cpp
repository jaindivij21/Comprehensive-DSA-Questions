// Subarray Sum equals K
// Given an array and an interger k, find teh total number of continuous subarrays whose sum equals
// to k.

// O(n2)

#include<iostream>

using namespace std;

int main() {
    // Take the array and k input
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int arr[n];

    // make a array that holds cumulative sum
    int cumSum[n];

    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // cumulative Sum calculate
    cumSum[0] = 0;  // MAKE THE FIRST ELEMENT IN CUMSUM ARRAY AS 0
    cumSum[1] = arr[0];
    for (int i = 2; i <= n; i++) {
        cumSum[i] = cumSum[i - 1] + arr[i-1];
    }
    // Enter the sum of subarrays
    int k;
    cout << "Enter the sum of subarray" << endl;
    cin >> k;

    // Using the concept to calculate the number of subarrays
    int count = 0;

    // traversing through cumSum
    for (int i = 0; i <= n; i++) {
        // if cumSum[i] - k exists in our cumSum array than a subarray exists
        // OR you can say that if cumSum[i] - (some)cumSum[j] = k, then subarray exists
        int difference = cumSum[i] - k;
        for (int j = 0; j < i; j++)
            if (cumSum[j] == difference) {
                count++;    // subarray found
                cout << "Subarray found from position " << j + 1 << " to " << i << endl;
            } else
                continue;
    }

    return 0;
}