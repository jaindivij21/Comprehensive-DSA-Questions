/*

1 2 3 4 5       n = 5  i = 5  (0)               
1 2 3 4 *        n = 5  i = 4  (1)
1 2 3 * * *      n = 5  i = 3  (3)   
1 2 * * * * *       n = 5  i = 2 (5)
1 * * * * * * *     n = 5  i = 1 (7)

*/

#include<iostream>
using namespace std;
int main() {
    int n,i,j;
    cin>>n;
    int k = -1;
    for(int i=n;i>0;i--)
    {
        for(int j=1;j<=i;j++)
        {
            cout<<j<<" ";    
        }
        // for(int j=n-1;j>=2*(i-2);j--)  
        // {
        //     cout<<"*";
        //     cout<<" ";      
        // }                                                    // Both works. But the commented is more space efficient
        for(int j=0;j<k;j++)  
        {
            cout<<"*";
            cout<<" ";      
        }
        k += 2;
        cout<<endl;
    }
	return 0;
}