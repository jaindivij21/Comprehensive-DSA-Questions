// Program to reverse a number

#include<iostream>
using namespace std;
int reverseNumber(int number)
{
    int newNumber = 0;
    while(number>0)
    {
        newNumber = (newNumber*10) + (number%10);
        number /= 10;
    }
    return newNumber;
}
int main() {
	int n;
	cin>>n;
	int temp = reverseNumber(n);
	cout<<temp<<endl;
	return 0;
}