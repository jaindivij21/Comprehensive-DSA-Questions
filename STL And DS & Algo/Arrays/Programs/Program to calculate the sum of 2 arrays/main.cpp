// program to add 2 arrays

#include<iostream>
using namespace std;

void addArray(int arr1[], int arr2[], int n1, int n2, int flag)
{
    int temp = n1>=n2?n1-n2:n2-n1;
    if(n1>=n2)
    {
        for(int i = temp; i < n1; i++)
            arr1[i] += arr2[i-temp];
    }
    else
    {
        for(int i = temp; i < n2; i++)
            arr2[i] += arr1[i-temp];
    }
}

int main()
{
    // input the both arrays
    int n1, n2;
    cin>>n1;
    int arr1[n1];
    for(int i = 0; i < n1; i++)
        cin>>arr1[i];
    cin>>n2;
    int arr2[n2];
    for(int i = 0; i < n2; i++)
        cin>>arr2[i];

    int flag = 0;
    if(n1>=n2)
        flag = 1;
    else
        flag = 2;

    // main function
    addArray(arr1, arr2, n1, n2, flag);

    if(flag==1) {
        //print the result array
        for (int i = 0; i < n1; i++)
            cout<<arr1[i]<<", ";
        cout<<"END"<<endl;
    }
    else
    {
        for (int i = 0; i < n2; i++)
            cout<<arr2[i]<<", ";
        cout<<"END"<<endl;
    }
}