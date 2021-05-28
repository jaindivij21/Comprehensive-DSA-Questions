// Program to calculate power of a number using recursion

#include<iostream>

using namespace std;

int powerCal(int num, int p) {
    // base condition
    if (p == 0)
        return 1;
    else {
        // recursive case
        return num * powerCal(num, p - 1);
    }
}

int main() {
    // input num and power
    int num;
    int power;

    cin >> num >> power;


    // main part
    cout << powerCal(num, power) << endl;

    return 0;
}
