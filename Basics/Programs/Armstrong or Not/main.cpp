// Program to check if a number is armstrong number

#include<iostream>
#include<cmath>
using namespace std;

bool checkArm(int n)
{
    int temp = n;
    int sum = 0;
    while (n>0)
    {  
        int a = n%10;
        sum += a*a*a;
        n /= 10;
    }    
    if (sum == temp)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cout<<"Enter the number"<<endl;
    cin>>n;

    cout<<checkArm(n);
    return 0;
}