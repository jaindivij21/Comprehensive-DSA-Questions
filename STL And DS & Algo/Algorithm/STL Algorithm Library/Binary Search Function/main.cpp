// Program to show binary search func in algortihm stl

#include <iostream>
#include<algorithm>

using namespace std;

// program to implement binary search manually and using STL's algorithm library and demonstrate use of 'lower_bound"

int main() {
    int n;
    n = 12;
    int arr[] = {0, 1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9};

    // array needs to be sorted for binary search to occur
    sort(arr, arr + n);

    int toBeSearched = 5;

    // implementing a search using STL
    bool present = binary_search(arr, arr + n, toBeSearched);
    if (present)
        cout << "Item was found" << endl;
    else
        cout << "item not found" << endl;

    // If we need to get the index of the element to be searched
    // use lower_bound and upper_bound functions
    // they return the lower address and upper bound + 1 addresse in form of iterators

    // Lower Bound
    auto itr1 = lower_bound(arr, arr + n, toBeSearched);   // itr is of the type int * i.e. a pointer to an int value
    int index1 = itr1 - arr;
    cout << "Lower bound of " << toBeSearched << " is " << index1 << endl;

    // Upper Bound
    int *itr2 = upper_bound(arr, arr + n, toBeSearched);
    int index2 = itr2 - arr;
    cout << "Upper bound of " << toBeSearched << " is " << index2 << endl;
    

    // number of same elements
    cout << "No of elements " << index2 - index1 << endl;
    return 0;
}
