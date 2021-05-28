// Program for Bubble Sort using recursion
// Bubble Sort is basically pushing the largest element towards the end of the array

#include<iostream>

using namespace std;

void recursiveBSort1(int arr[], int n) {
    // recursive bubble sort but with iteration

    // base case
    if (n == 1) {
        // only one element, then its sorted
        return;
    } else {
        // recursive call
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1])
                swap(arr[i], arr[i + 1]);
        }
        recursiveBSort1(arr, n - 1);
        return;
    }
}

void recursiveBSort2(int arr[], int n, int j) {
    // only** recursive bubble sort (no use of iteration)
    // it' ll have 2 base cases

    // base cases
    if (n == 1) {
        // length of array is 1 then its sorted (means all the passes are complete)
        return;
    }
    if (j == n - 1) {
        // j which is our iterator is at the last index, means one pass is completed
        // recursive call 1 (that happens after one pass ends)
        recursiveBSort2(arr, n - 1, 0);  // reset j to 0 for the next iteration
    }

    // recursive call 2 (that happens for iterations in each pass)
    if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
    }
    recursiveBSort2(arr, j + 1, n);

}

int main() {
    // input the info

    cout<<"Enter the size"<<endl;
    int n;
    cin >> n;

    cout<<"Enter the array"<<endl;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // main funciton to sort the array recursively
    recursiveBSort1(arr, n);
    recursiveBSort2(arr, n, 0);

    // print sorted array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}