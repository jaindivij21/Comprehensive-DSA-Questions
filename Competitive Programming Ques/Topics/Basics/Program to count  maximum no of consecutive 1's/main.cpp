#include <bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;           //take the input for a number
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int count=0;                                    //initiate count
    int maximum=0;                              //initiate maximum

    //run the loop from the number until its 0 and every time divide the number by 2; store the remainders; the sequence of the remainders is your binary
    for(int i=n;i!=0;i=i/2){                    //run a loop (do the multiple division thing to calculate the binary from decimal)
        int rem=i%2;                            //store the remainder in rem for every iteration
        if(rem==1) {
            count++;                            //if the rem is 1; increment count and compare it with max in evry iteration
        }
        if(rem==0)                                  //if rem is 0 then make count==0;; but we have maximum which already stores max consecutive 1's
            count=0;
        maximum=max(maximum,count);
    }

    cout<<maximum;

    return 0;
}
