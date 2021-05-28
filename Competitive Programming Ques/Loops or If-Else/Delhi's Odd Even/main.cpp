// Delhi's Odd Even https://www.hackerrank.com/contests/launchpad-1-winter-challenge/challenges/delhis-odd-even

#include<iostream>

using namespace std;

int evenSum = 0, oddSum = 0;


int reverseNumber(int carNumber)
{
    int newNumber = 0;
    while(carNumber>0)
    {
        newNumber = (newNumber*10) + (carNumber%10);
        carNumber /= 10;
    }
    return newNumber;
}

void calSum(int number)
{
    evenSum = 0;
    oddSum = 0;
    int c = 1;  // denotes the first i.e the odd place
    while (number!=0)
    {
        if ( c % 2 == 0)
        {
            // even
            evenSum += number%10;
            number /= 10;
        }
        else
        {
            // odd
            oddSum += number%10;
            number /= 10;
        }
        c++;
    }
}

int main()
{
    int testCases;
    cin>>testCases;

    while(testCases--)
    {
        int carNumber;
        cin>>carNumber;
        int number = reverseNumber(carNumber);
        calSum(number);

        if (evenSum % 4 == 0 || oddSum % 3 == 0)    
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}