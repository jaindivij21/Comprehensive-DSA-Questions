// selection sort

#include<iostream>
#include<climits>
using namespace std;

void selectionSort(int arr[], int size)
{
    for(int i = 0; i < size-1; i++)
    {
        int minIndex = i;
        for(int j = i; j<size; j++)
        {
            if(arr[j]<arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
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

    selectionSort(arr, size);

    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    return 0;
}