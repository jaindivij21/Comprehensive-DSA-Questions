// print the first and last occurence of a number in a sorted array

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    // input the number of array elements
    int n;
    cin >> n;
    // input the array
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // input the number of queries
    int queries;
    cin >> queries;
    // for each query
    while (queries--) {
        // number input
        int num;
        cin >> num;
        bool temp = binary_search(arr, arr + n, num);
        // if number is present
        if (temp) {
            // print its lower bound INDEX and Upper bound INDEX
            cout << lower_bound(arr, arr + n, num) - arr << " " << upper_bound(arr, arr + n, num) - 1 - arr << endl;
        } else  
            // print -1
            cout << "-1 -1" << endl;
    }

    return 0;;
}
