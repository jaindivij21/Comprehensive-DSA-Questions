#include<iostream>

using namespace std;

void merge(int a[], int s, int e) {
    int mid = (s + e) / 2;

    // initialize the values
    int i = s;
    int j = mid + 1;
    int k = s;  // important

    int temp[100];

    // main merge part
    while (i <= mid && j <= e) {
        if (a[i] < a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = a[i++];
    }
    while (j <= e) {
        temp[k++] = a[j++];
    }

    //We need to copy all element to original arrays
    for (int i = s; i <= e; i++) {
        a[i] = temp[i];
    }


}

// main function
void mergeSort(int a[], int s, int e) {

    // Base case (1 or 0 elements in the array); means the array is already sorted
    if (s >= e) {
        return;
    }

    // Follow 2 steps
    // Divide the array into 2 parts, sort both the parts and then merge them in ascending order
    int mid = (s + e) / 2;

    //Recursively the arrays - s,mid and mid+1,e
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);

    //Merge the two parts
    merge(a, s, e);

}


int main() {

    // input the array
    int a[100];
    cout << "Enter the size" << endl;
    int n;
    cin >> n;

    cout << "Enter the array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // main function
    mergeSort(a, 0, n - 1);

    // print the sorted array
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}