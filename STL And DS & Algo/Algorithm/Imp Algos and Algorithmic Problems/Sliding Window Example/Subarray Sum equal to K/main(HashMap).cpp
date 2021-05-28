// Subarray Sum equals K
// Given an array and an interger k, find teh total number of continuous subarrays whose sum equals
// to k.
// Solving using hash map O(N)

#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
    // Take the array and k input
    int n;
    cout << "Enter the number of elements" << endl;
    cin >> n;
    int arr[n];

    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Enter the sum of subarrays
    int k;
    cout << "Enter the sum of subarray" << endl;
    cin >> k;

    // Using the concept to calculate the number of subarrays
    int count = 0;

    // make a unstructured map to contain/store the cumulative sums
    unordered_map<int, int> map;    // map basically collects all your cumsums

    // loop through the array
    int cumSum = 0;
    map[0] = 1; // mandatory
    for (int i = 0; i < n; i++) {
        cumSum += arr[i];   // cal cumSum
        int difference = cumSum - k;    // need to find this value in your map
        // if it exists, means that subarray also exists
        if (map.find(difference) != map.end())
            count += map[difference];   // if it exists in the map you add its map value to count
        if (map.find(cumSum) != map.end())
            map[cumSum]++;  // also add cumSum to map 
        else
            map[cumSum] = 1;
    }

    cout << "The number of sub arrays is " << count << endl;

    return 0;
}