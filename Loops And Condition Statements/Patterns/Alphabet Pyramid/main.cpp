#include<iostream>
using namespace std;

/* 
A
BB
CCC
DDDD
EEEEE
*/

int main()
{
    int n;
    cout<<"Enter the number of rows"<<endl;
    cin>>n;

    char temp = 'A';

    for (int i = 1; i<=n; i++)
    {
        for(int j = 0; j<i; j++)
        {
            cout<<temp;
        }
        temp = temp+1;
        cout<<endl;
    }

    return 0;
}
