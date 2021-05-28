// calculate factorial of really large numbers

#include<iostream>
using namespace std;
#define MAX 500

int multiply(int arr[], int x, int len)
{
    int carry = 0;
    int i = 0;
    int temp = 0;

    for(; i < len; i++)
    {
        // multiply each digit w the number x and store the carry to be added in the next number
        temp = 0;
        temp = x * arr[i] + carry;
        arr[i] = (temp%10);
        carry = temp/10;
    }

    // if end carry is also generated, even that has to be accomodated in the ans
    while(carry != 0)   //18    === 8 1
    {
        temp = carry%10;
        carry /= 10;
        arr[i] = temp;
        len++;
        i++;
    }
    // final lenght of the number is returned so that it can be printed easily
    return len;
}

void factorial(int n)
{
    int arr[500];
    // The array initially contains 1
    arr[0] = 1;
    int arrLeng = 1;

    // multiply the nth number with n+1 to obtain the factorial
    for(int i = 2; i <=n; i++)
        arrLeng = multiply(arr, i, arrLeng);

    // print the final ans array though in reverse order
    for(int i = arrLeng-1; i >= 0; i--)
        cout<<arr[i];
    cout<<endl;
}

int main()
{
    // input the number
    int n;
    cin>>n;

    // call the main function
    factorial(n);
    return 0;
}