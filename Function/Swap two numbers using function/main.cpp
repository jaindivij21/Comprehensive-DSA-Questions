#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;

//program to swap the values of two numbers

void swap(int *a, int *b);

int main() {
    int a, b;
    cout<<"Enter the values of a and b"<<endl;
    cin>>a;
    cin>>b;
    cout<<"\n";
    cout<<"The original value of a and b are: " <<a <<", " <<b <<endl;
    swap(&a, &b);
    cout<<"The new value of a and b are: " <<a <<", " <<b <<endl;
    getch();
    return 0;
}

void swap(int *first, int *second){
    int temp;
    temp=*second;
    *second=*first;
    *first=temp;
}
