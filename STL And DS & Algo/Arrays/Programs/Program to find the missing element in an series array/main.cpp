// Program to find the missing element from an array

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int sizeOfArr;
    cin>>sizeOfArr;

    // Input the array
    int arr[sizeOfArr];
    for(int i=0; i<sizeOfArr-1; i++)
        cin>>arr[i];

    // finding the missing element
    int x1 = arr[0];
    int x2 = 1;
    for(int i =1; i<sizeOfArr-1; i++)
        x1 = x1^arr[i];
    for(int i=2; i<=sizeOfArr; i++)
        x2 = x2^i;

    x1 = x1^x2;

    cout<<"Missing element is "<<x1<<endl;


    return 0;
}