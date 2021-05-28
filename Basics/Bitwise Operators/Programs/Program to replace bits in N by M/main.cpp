// program to insert a set of bits into another set of bits with given positions using bitwiswe operators

#include<iostream>
using namespace std;

int clearBits(int num, int i, int j)
{
    int allOnes = ~0;
    int a = allOnes << (j+1);
    int b = (1 << i) - 1;
    int mask = a|b;
    return (num & mask);
}

int main()
{
    // input the numbers
    int n;
    cout<<"Enter the first (bigger) number"<<endl;
    cin>>n;
    int m;
    cout<<"Enter the second substr (smaller) number"<<endl;
    cin>>m;

    int i, j;
    cout<<"Enter the positions from the right of n"<<endl;
    cin>>i>>j;

    // step 1 is to clear the bits in n of respective positions
    int temp = clearBits(n, i, j);
    // step 2 is to do an or with left shifted number m
    int ans = temp | (m << i);

    cout<<"The ans is "<<ans<<endl;

    return 0;
}