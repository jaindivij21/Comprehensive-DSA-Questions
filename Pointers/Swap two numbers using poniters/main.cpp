#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

//program to swap the two numbers

void swap(int *n1, int *n2);

int main() {
    int a, b;
    cout<<"Enter the two numbers";
    cin>>a>>b;
    cout <<"The values are:" <<a <<" " <<b <<endl;

    swap(&a, &b);

    cout <<"The values are:" <<a <<" " <<b <<endl;

    getch();
    return 0;
}

void swap(int *n1, int *n2){
    *n1=*n1+*n2;
    *n2=*n1-*n2;
    *n1=*n1-*n2;
}