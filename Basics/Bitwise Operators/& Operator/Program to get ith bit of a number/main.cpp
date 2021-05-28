// Using bitwise operators get the i th bit of a number

#include<iostream>

using namespace std;

int getBit(int num, int pos) {
    return (num & (1 << pos)) > 0 ? 1 : 0;
}

int main() {
    cout << "Enter the number" << endl;
    int num;
    cin >> num;
    cout << "Enter the position" << endl;
    int i;
    cin >> i;

    cout << getBit(num, i) << endl;

    return 0;
}