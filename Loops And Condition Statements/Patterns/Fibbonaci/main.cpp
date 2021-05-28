// program to print the fibonaci series

#include<iostream>
using namespace std;

// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 

printFib(int num)
{
    int n1 = 0, n2 = 1;
    int n3 = 0;
    cout<<"0 1 ";
    for(int i = 0; i < num-2; i++)
    {
        n3 = n1 + n2;
        cout<<n3<<" ";
        n1 = n2;
        n2 = n3;

    }
}


int main()
{
    cout<<"Enter the number of elements ";
    int n;
    cin>>n;

    printFib(n);
}