// Program to read a list of Strings and store it in a 2d Char Array

#include<iostream>
using namespace std;

int main()
{
    // array to store all the strings
    char arr[100][1000];

    cout<<"Enter the total number of strings"<<endl;
    int n;
    cin>>n;
    // ignore extra cin
    cin.ignore();
    int temp;
    for(int i = 0; i < n; i++)
    {
        // input a char array i.e string in every row upto n rows with max of 1000 char/row with the default delimiter
        // being '\n'
        cin.getline(arr[i],1000);
    }

    // Print the strings
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<endl;
    return 0;
}