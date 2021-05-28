#include <iostream>
#include<algorithm>

using namespace std;

// program to implement binary search manually and using STL's algorithm library and demonstrate use of 'lower_bound"

void show(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int binarySearch(int arr[], int x, int l, int u) {
    int mid;
    if (l >= 0 && u >= 1) {
        mid = (l + u) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return binarySearch(arr, x, mid + 1, u);
        else
            return binarySearch(arr, x, l, mid - 1);
    }
    // if not found
    return -1;
}

int main() {
    int n;
    cout << "Input the random array size :";
    cin >> n;
    int arr[n];

    // input the array
    cout << "Enter the elements:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // array needs to be sorted
    show(arr, n);
    cout << "Sorting the array..." << endl;
    sort(arr, arr + n);
    cout<< "Sorted Array: ";
    show(arr, n);

    int toBeSearched;
    cout << "Enter the element to be searched?";
    cin >> toBeSearched;

    int type;
    cout << "Enter the method of search 1) STL Binary Search 2) Manual Binary Search";
    cin >> type;

    switch (type) {
        case 1:
            // implementing a search using STL
            if (binary_search(arr, arr + n, toBeSearched))
                cout << "Item was found at " << lower_bound(arr, arr + n, toBeSearched) - arr << endl;
            else
                cout << "item not found" << endl;
            break;
        case 2:
            // implementing manual Binary Search Algorithm
            int ans = binarySearch(arr, toBeSearched, 0, n - 1);
            if (ans != -1)
                cout << "Element found at " << ans << " position" << endl;
            else
                cout << "Element not found" << endl;
            break;
    }


    return 0;
}
