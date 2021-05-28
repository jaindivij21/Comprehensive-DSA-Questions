// Counting Sort
// To be used only when the array has some specific range from 0-n (Since it takes alot of time)
// Stable Sort
// Time Complexity - O(n+k)
// Space Complexity - O(n+k)

#include<iostream>
#include<climits>

using namespace std;

void countingSort(int n, int arr[], int finalArr[], int max) {
    // add the counts of each number from the main array and store them in array of length maximum
    int count[max+1] = {0};

    // this stores the count of each element in arr in an array count
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // make the sum cumulative (count(i-1)+count(i))
    for (int i = 0; i < max+1; i++) {
        if (i == 0)
            continue;
        else
            count[i] = count[i - 1] + count[i];
    }
    
    // sort the array by putting the vlaues in finalArray
    // in each iteration put the element from arr into finalArr on position from count[] - 1 of that element
    for (int i = 0; i < n; i++) {
        finalArr[count[arr[i]]-1] = arr[i];
        // also decr the count of that element
        count[arr[i]]--;
    }
}

int main() {
    // input the size
    int size;
    cin >> size;

    int arr[size];

    int largest = INT_MIN;
    // input the array & measure max val
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        largest = max(largest, arr[i]);
    }

    // final array that is sorted
    int finalArr[size];

    // main funct
    countingSort(size, arr, finalArr, largest);

    // print the results
    for (int i = 0; i < size; i++)
        cout << finalArr[i] << " ";
    cout << endl;

    return 0;
}