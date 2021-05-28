// program to print the fibonaci series

#include<iostream>
using namespace std;

// 1 1 2 3 5 8 13 21 34 55 89 144 233 377 

int main()
{
    cout<<"Enter the number of rows (max = 10) ";
    int n;
    cin>>n;

    int n1 = 0;
    int n2 = 1;
    int n3 = 1;

    for(int i =0; i< n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(i == 0)
            {
                cout<<"1";
                break;
            }
            else
            {
                cout<<n3<<" ";
            }
            n1 = n2;
            n2 = n3;
            n3 = n2+n1;
        }
        cout<<endl;
    }

    return 0;
}
