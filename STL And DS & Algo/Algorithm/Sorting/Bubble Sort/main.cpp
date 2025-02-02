// bubble sort
// follows pairwise swapping

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - 1 - i; j++)
    {
      if (arr[j] > arr[j + 1])
        swap(arr[j], arr[j + 1]);
    }
  }

  return;
}

int main()
{
  // input the array
  int size;
  cout << "Enter the size:";
  cin >> size;
  int arr[size];

  for (int i = 0; i < size; i++)
    cin >> arr[i];

  bubbleSort(arr, size);

  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  return 0;
}