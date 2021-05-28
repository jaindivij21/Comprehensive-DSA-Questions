// program to convert decimal to octal

#include<iostream>
using namespace std;

int convertOct(int number)
{
    int newNumber = 0;
    int temp = 1;   
    while(number != 0)
    {
        newNumber += temp*(number%8);
        number /= 8;
        temp *= 10;
    }
    return newNumber;
}


int main()
{
    int number;
    cout<<"Enter the number in decimal ";
    cin>>number;

    cout<<convertOct(number)<<endl;

    return 0;
}