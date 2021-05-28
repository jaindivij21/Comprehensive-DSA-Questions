// Divisible subarray Problem
// https://www.geeksforgeeks.org/count-sub-arrays-sum-divisible-k/

// Find all the subarrays in an array whose sum is divisible by a number k
// https://www.youtube.com/watch?v=QM0klnvTQzk

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

    // make a unstructured map to contain/store the cumulative sums%k
    unordered_map<int, int> map;    // map basically collects all your cumsums%k

    // maintain a cumulative sum array
    int cumSum = 0;
    map[0] = 1; // mandatory cuz 0 appears for the first time
    for (int i = 0; i < n; i++) {
        cumSum += arr[i];   // cal the cumulative sum
        int remainder = cumSum % k;    // cal the remainder
        // if the remainder is -ve
        if (remainder < 0) {
            remainder += k; // ex. remainder is -4 and k = 7, then rem = 3 (-4+7)
        }

        // Acc to the concept we need to check if remainder has come before or not & if yes how many times (a%k = b%k)
        if (map.find(remainder) != map.end()) {
            // we found the number
            count += map[remainder];
            map[remainder]++;
        } else {
            map[remainder] = 1;
        }
    }

    cout << "The number of sub arrays are: " << count << endl;


    return 0;
}