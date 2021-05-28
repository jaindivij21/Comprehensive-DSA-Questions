// Greedy Algorithm to find Minimum number of Coins
/*
 *  TC: O(N)
 *  Doesn't work for some denominations. For those problems we use DP :-
 *       denominations {9, 6, 5, 1} and V = 11. The above approach would print 9, 1 and 1. Actual Ans: 2 denominations 5 and 6.
 */


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

void findMin(int arr[], int n, int size) {
    // sorting is necessary of the denominations array
    sort(arr, arr + size);

    // vector to store ans denominations
    vector<int> v;

    // loop through the denominations from biggest to smallest
    for (int i = size - 1; i >= 0; i--) {
        // push this specific denominations as many times as its possible
        while (n >= arr[i]) {
            // while the value is greater than the change denomination, add the denomination to the array
            v.push_back(arr[i]);
            n -= arr[i];    // decrease the value by the amount equal to denomination
        }
    }

    // print the result
    cout << "The number of denomination coins used: " << v.size() << endl;
    cout << "The actual denominations are:" << endl;
    for (auto itr:v) {
        cout << itr << " ";
    }
    return;
}

int main() {
    int denominations[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int size = sizeof(denominations) / sizeof(int);

    int n;
    cout << "Enter the value whose change is required in least number of denominations" << endl;
    cin >> n;

    findMin(denominations, n, size);

    return 0;
}