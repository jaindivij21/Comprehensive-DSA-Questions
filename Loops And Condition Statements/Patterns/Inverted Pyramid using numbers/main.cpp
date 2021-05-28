#include<iostream>
using namespace std;

/*
12345
1234
123
12
1
*/

int main()
{   
    int n;
    cout<<"Enter the number of rows ";
    cin>>n;

    for(int i = n; i!=0; i--) 
    {
        for(int j = i; j != 0; j--) 
        {
            cout<<i-(j-1)<<" ";
        }
        cout<<endl;
    }

    return 0;
}