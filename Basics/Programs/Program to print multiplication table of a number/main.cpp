#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

//Program to print multiplication table of a number

void mult(int num);


int main() {

    cout<<"Enter the number: ";
    int num;
    cin >> num;
    mult(num);

    return 0;
}

void mult(int num){
    for (int i = 1; i <= 10; i++) {
        cout << num << "x" << i << "=" << (num * i) << endl;
    }
}
