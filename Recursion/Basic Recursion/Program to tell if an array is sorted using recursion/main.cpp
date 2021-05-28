// Program to check if an array is sorted using recursion

#include<iostream>

using namespace std;

// recursive funciton that tells if an array is sorted or not
bool isSorted(int n, int arr[]) {
    // base case
    if (n == 0 or n == 1)   // if our array contains either no or just 1 element it is sorted
        return true;
    // recursive case
    if (arr[0] < arr[1] and isSorted(n - 1, arr + 1)) {
        return true;
    }
    return false;
}

int main() {
    // input the array
    int size;
    cin >> size;

    int arr[size];
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    // main part
    cout << isSorted(size, arr) << endl;

    return 0;
}