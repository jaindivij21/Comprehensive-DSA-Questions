// Program to make linear search using recursion
// Basically return the index of the last occurence of a number in an array

#include<iostream>

using namespace std;

// difference bw this and first occurence is that here we will first call the recursive function and write other code
int search(int arr[], int n, int x) {
    if (n == 0) {
        // base case
        return -1;
    } else {
        // recursive cases
        int temp = search(arr + 1, n - 1, x);   // first check in remaining array
        if (temp == -1)
        {
            // if not found in remaining array,
            // then check for the initial pos
            if(arr[0] == x)
                return 0;   // return 0 if found
            else
                return -1;  // keep returning -1 if not found
        }
        else
            return temp + 1;    // but if last occurence has been found earlier in remaining array, no need to check for inital postion
            // just return its index(temp value) + 1(which accounts for initial arr[0] postion)
    }
}

int main() {
    // input the array and its size
    cout << "Enter the array size" << endl;
    int n;
    cin >> n;

    cout << "Enter the array" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // element to be be found
    int x;
    cout << "Enter the element to be searched" << endl;
    cin >> x;

    cout << "Index of the first occurence of " << x << " is: " << search(arr, n, x) << endl;
    return 0;
}
