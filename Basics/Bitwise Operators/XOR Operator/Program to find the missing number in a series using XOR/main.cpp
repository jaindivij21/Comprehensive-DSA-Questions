// Porgram to find the missing number in a continuous series using XOR only
// Complexity: (O(N))

#include<iostream>
using namespace std;

int main()
{
    int arr[] ={2};
    int size = sizeof(arr)/ sizeof(arr[0]);

    int x = arr[0];
    int y = 1;

    for (int i = 1; i < size; i++)
    {
        x ^= arr[i]; 
    }

    for (int i = 2; i <= size+1; i++)
    {
        y ^= i; 
    }

    x = x^y;
    cout<<"Missing Number "<<x;
    return 0;
}