// Program to print all the pythgorean triplets below a limit

#include<iostream>

typedef unsigned long long ll; 
using namespace std;

void printAll(ll limit)
{
    // formulas to be used:
    // a = m*m - n*n
    // b = 2mn
    // c = m*m + n*n
    // also here m > n
    int m = 2;
    ll a,b;
    ll c = 0;  // c is the largest of the 3
    while(c < limit)
    {
        for(int n = 1; n < m; n++)
        {
            a = m*m - n*n;
            b = 2*m*n;
            c = m*m + n*n;

            if (c>limit)
                break;
            cout<<a<<" "<<b<<" "<<c<<endl;
        }
        m++;
    }
}

int main(){
    // input the limit
    cout<<"Enter the limit"<<endl;
    ll limit;
    cin>>limit;

    printAll(limit);
    return 0;
}