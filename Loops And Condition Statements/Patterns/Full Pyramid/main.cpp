#include<iostream>
using namespace std;

/*

        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

*/

int main()
{
    int n;
    cout<<"Enter the number of rows "; 
    cin>>n;

    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        for(int j = n-i-1; j!= 0; j--)
            cout<<"  ";
        for(int k = 0; k<temp; k++)
            cout<<"* ";
        temp += 2;
        cout<<endl;
    }   
    return 0;
}