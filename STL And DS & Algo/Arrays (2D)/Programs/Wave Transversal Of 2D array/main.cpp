// Program to showcase wave transversal in a 2D array

#include<iostream>
using namespace std;

int main()
{
    int rows, columns;
    cin>>rows>>columns;

    int arr[100][100];

    //input the array
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
            cin>>arr[i][j];
    }

    //original array
    cout<<"Original Array"<<endl;
    for(int i = 0; i<rows; i++)
    {
        for(int j = 0; j<columns; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl;

    cout<<"Wave Transversal"<<endl;
    // wave transveral
    for (int j = 0; j < columns; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < rows; i++)
                cout << arr[i][j] << ", ";
        } else {
            for (int i = rows-1; i >= 0; i--)
                cout << arr[i][j] << ", ";
        }
    }
    cout << "END" << endl;
    return 0;
}