// Count the number of trailing zeros in
// https://www.geeksforgeeks.org/count-trailing-zeroes-factorial-number/

#include<iostream>
using namespace std;

int countZeros(int n)
{
    int ans = 0;
    for(int D = 5; n/D > 0; D = D*5)
        ans += n/D;

    return ans;
}

int main()
{
    // input the number
    long long int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<countZeros(n)<<endl;
}