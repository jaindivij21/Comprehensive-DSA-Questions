// Program to print a pascal triangle

/*

           1
         1   1
       1   2   1
     1   3   3   1
   1   4   6   4   1
 1   5   10   10   5   1 

 */

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    int temp = 0;
    for( int i=0; i<n; i++) 
    {
        for(int j = 0; j<n-i; j++)
          cout<<"  ";
        for(int k = 0; k<=i; k++) 
        {
          if(i == 0 || k == 0)
            temp = 1;
          else
          {
            temp = (temp*(i-k+1))/k; 
          }
          cout<<temp<<"   ";
        }
        cout<<endl;
    }

    return 0;
}