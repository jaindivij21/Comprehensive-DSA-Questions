// https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long n,k,i,l,r;
        cin>>n>>k;
        int a[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        for(i=0;i<n;i=i+k)
        {
            l=i;
            r=min(i+k-1,n-1);
            while(l<r)
                swap(a[l++],a[r--]);
        }
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        if(t!=0)
            cout<<"\n";
    }
    return 0;
}