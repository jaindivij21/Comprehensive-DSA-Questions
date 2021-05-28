// Find the next greatest element in the circular array

#include<iostream>

using namespace std;

int main() {
    // input the size and elements of circular array
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // main part (Naive/Brute force O(n2) approach)
    for (int i = 0; i < n; i++) {
        // for all the elements
        
        // start from the next element in the circular array 
        int j = (i + 1) % n;
        while (j != i) {
            // if the greater element found print it and break
            if (arr[j] > arr[i]) {
                cout << arr[j] << " ";
                break;
            }
            j = (j + 1) % n;
        }
        // if the the greater element is not found print -1
        if (j == i)
            cout << -1 << " ";
    }

    return 0;
}