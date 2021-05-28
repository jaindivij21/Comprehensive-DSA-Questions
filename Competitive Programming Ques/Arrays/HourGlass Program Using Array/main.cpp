//https://www.hackerrank.com/challenges/30-2d-arrays/problem?isFullScreen=true

#include <bits/stdc++.h>
#include<algorithm>
using namespace std;

//Hourglass Problem

int main()
{
    int arr[6][6];
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            cin>>arr[i][j];
        }
    }

    int sum=0;
    int maximum=-100;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            sum=arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            maximum=max(maximum,sum);
        }
    }

    cout<<maximum;

    return 0;
}
