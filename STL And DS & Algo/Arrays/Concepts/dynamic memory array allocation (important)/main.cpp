#include <iostream>


using namespace std;


int main() {
    int size;  // variable declaration
    cout<<"Enter the size of the array : ";
    cin >> size;    //
    int *arr = new int[size];   // creating an array

    cout<<"\nEnter the element : ";
    for(int i=0;i<size;i++)   // for loop
    {
        cin>>*(arr+i);                                        // or USE cin>>arr[i];
    }
    cout<<"\nThe elements that you have entered are :";
    for(int i=0;i<size;i++)    // for loop
    {
        cout<<arr[i]<<",";                                 // or USE cout<<*(arr+i)<<",";
    }
    delete[]arr;  // deleting an existing array.
    getch();
    return 0;
}

