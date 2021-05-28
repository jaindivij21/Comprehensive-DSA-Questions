// Program to define the use of find function

#include<iostream>
#include<algorithm>

using namespace std;

int main() {
    // find function lets you search a specific element in a data structure or array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(int);

    int elementToBeFound;
    cin >> elementToBeFound;

    // working of the find function
    auto itr = find(arr, arr + n, elementToBeFound);    // the func returns an iterator
    
    /*
    *   basically the function needs the starting address of the array, the address
    *   after the last element (last element is at arr+(n-1)), and the key to be found
    *
    *   if itr = n i.e address one more than the end of the array, it means that element not found
    *   else itr returns the address of the element. once you have the address, you can compute the index
    */
    
    int index = itr - arr;
    if (index == n)
        cout << "Element not found" << endl;
    else
        cout << "Element found at index:" << index << " and address:" << itr << endl;
    return 0;
}