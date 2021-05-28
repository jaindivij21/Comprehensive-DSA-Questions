// Using bitwise operators telling if a number is odd or even

#include<iostream>

using namespace std;

int main() {
    // funda is that in odd numbers LSB is always one
    cout << "Enter the number" << endl;
    int num;
    cin >> num;

    if (num & 1)
        cout<<"Odd"<<endl;
    else
        cout<<"Even"<<endl;

        return 0;
}