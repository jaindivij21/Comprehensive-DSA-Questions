// Recursive program to print the fibonaci series

#include<iostream>
using namespace std;

// 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 

int n1 = 0, n2 = 1;
void printfibo(int num)
{
    if(num>0){
    int n3 = n1 + n2;
    cout<<n3<<" ";
    n1 = n2;
    n2 = n3;
    printfibo(num - 1);
}}


int main()
{
    cout<<"Enter the number of elements to be printed ";
    int n;
    cin>>n;
    cout<<"0 1 ";
    printfibo(n-2);

    return 0;
}