#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

//program to compute the factorial of a number using loops

int factorial(int a);

int main() {
    cout<<"Enter the number whose factorial is to be computed"<<endl;
    int a;
    cin>>a;
    int b = factorial(a);
    cout<<"The factorial of " <<a <<" is: " <<b;
    getch();
    return 0;
}

int factorial(int a){
    int fac=1;
    for(int i=a;i!=1;i--){
        fac=fac*i;
    }
    return fac;
}

