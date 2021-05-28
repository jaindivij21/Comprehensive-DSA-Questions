// insertion sort
// follows pairwise swapping

#include<iostream>
#include<climits>
using namespace std;

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

int main()
{
    // input the array
    int size;
    cout<<"Enter the size:";
    cin>>size;
    int arr[size];

    for(int i = 0; i < size; i++)
        cin>>arr[i];

    insertionSort(arr, size);

    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    return 0;
}