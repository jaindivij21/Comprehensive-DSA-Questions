// Program to make linear search using recursion
// Basically prints all the indexes of all the occurence of a number in an array

#include<iostream>

using namespace std;

// if we need to store the occurences in some other array
int storeOcc(int arr[], int i, int n, int x, int out[], int j) {
    int temp;
    // base case
    if (i == n)
        return j;   // returning the count
    else {
        if (arr[i] == x) {
            out[j] = i;
            // j is incremented
            return storeOcc(arr, i + 1, n, x, out, j + 1);
        }
        // j remains unchanged
        return storeOcc(arr, i + 1, n, x, out, j);
    }
}

// just to print all the indexes of the numbers
void search(int arr[], int i, int n, int x) {
    // base case
    if (i == n)
        return; // reached the eelement not found therefore not
    else {
        // recursive call
        if (arr[i] == x)
            cout << i << " ";
        // check if elememt exists in the following array
        search(arr, i + 1, n, x);
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

    int i = 0; // starting index of array
    search(arr, i, n, x);

    // function call to store the occurences of the key in an array output and also get the count of how many times the key appeared
    i = 0;
    int j = 0;
    int output[100];
    int count = storeOcc(arr, i, n, x, output, j);

    // print the results
    for (int k = 0; k < count; k++)
        cout << output[k] << " ";

    return 0;
}
