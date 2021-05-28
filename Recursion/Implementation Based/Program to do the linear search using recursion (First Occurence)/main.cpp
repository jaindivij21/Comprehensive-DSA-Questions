// Program to make linear search using recursion
// Basically return the index of the first occurence of a number in an array

#include<iostream>

using namespace std;

int search_method1(int arr[], int n, int x) {
    // base cases
    if (n == 0) // element not found
        return -1;

    // recursive call
    if (arr[0] == x)    //  if the first index is our element
        return 0;
    // if not the first element then search for the element in the reamining array
    int i = search_method1(arr + 1, n - 1, x);  // assume it works corrrectly
    if (i == -1)    // if remaining array retruns -1, it means it doesnt exist
        return -1;
    else
        return i + 1;   // if it returns a value 'i' then it means the index of that element is i+1
}

int search_method2(int arr[], int i, int n, int x) {
    // in this method we try to find teh element at the first index, if not found recusively try to find it in remaining array
    // i is basically our index

    // base case
    if (i == n) {
        // not found
        return -1;
    }
    // recursive case
    if (arr[i] == x) {
        // if found at the first index of array
        return i;
    } else {
        // ele find in the remaining array
        return search_method2(arr, i + 1, n, x);
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

    cout << "Index of the first occurence of " << x << " is: " << search_method1(arr, n, x) << endl;
    cout << "Index of the first occurence of " << x << " is: " << search_method2(arr, 0, n, x) << endl;
    return 0;
}
