// Some other important methods of algo stl lib 
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);

    // swap
    int a = 10;
    int b = 20;
    cout << "Original Value of a & b:" << a << " " << b << endl;
    swap(a, b);
    cout << "New Value of a & b:" << a << " " << b << endl;

    // min, max
    cout << max(a, b) << endl;
    cout << min(a, b) << endl;

    // reverse
    //original array
    for (int i = 0; i < n; i++)
        cout << arr[i];
    reverse(arr, arr + n);
    // new array
    for (int i = 0; i < n; i++)
        cout << arr[i];

    return 0;
}