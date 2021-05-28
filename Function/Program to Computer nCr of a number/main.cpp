// Program to compute nCr of a program

#include<iostream>
using namespace std;

int factorial(int num)
{
    int res = 1;
    while(num != 1)
    {
        res *= num;
        num--;
    }
    return res;
}

int nCr(int n, int r) {
    return factorial(n) / (factorial((n - r)) * factorial(r));
}

int main()
{
    // input the values
    cout<<"Enter the values of n and r"<<endl;
    int n, r;
    cin>>n>>r;

    // function to compute nCr
    cout<<"The ans is: "<<nCr(n, r)<<endl;

    return 0;
}