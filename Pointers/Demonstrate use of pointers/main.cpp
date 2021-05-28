#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

//program to demonstrate the use of pointers

int main() {
    int number;

    cin>>number;

    int *address;
    address=&number;

    cout<<"Value of the number is: " <<number <<" " <<*address <<endl;
    cout<<"Address of the number is: " <<&number <<" " <<address <<endl;

    getch();
    return 0;
}
