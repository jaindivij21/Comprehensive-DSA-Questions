// Program to calculate the sqrt of a number 

#include<iostream>
using namespace std;

int main()
{
    int number;
    int precision;
    cin>>number>>precision;

    float ans = 0;
    float inc = 1.0;

    while(ans*ans<=number)
    {
        for(int i=0; i<=precision; i++)
        {
            ans += inc;
        }
        ans -= inc;
        inc /= 10;
    }

    cout<<ans<<endl;


    return 0;
}