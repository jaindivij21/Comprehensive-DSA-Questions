#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

//program to compute the factorial of a number using recursive functions

int factorial(int a);

int main() {
    cout<<"Enter the number whose factorial is to be computed"<<endl;
    int a;
    cin>>a;
    int b = factorial(a);
    if(b==-1)
        cerr<<"ERROR";
    else
        cout<<"The factorial of " <<a <<" is: " <<b;
    getch();
    return 0;
}

int factorial(int a){
    if(a<0)
        return -1;
    else if (a==0)
        return 1;
    else
        return a*factorial(a-1);
}

