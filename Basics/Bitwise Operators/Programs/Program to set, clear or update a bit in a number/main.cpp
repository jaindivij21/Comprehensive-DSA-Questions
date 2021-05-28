// Using bitwise operators set, clear or update a bit in a number

#include<iostream>

using namespace std;


int main() {
    cout << "Enter the number" << endl;
    int num;
    cin >> num;
    cout << "Enter the position" << endl;
    int i;
    cin >> i;
    cout << "Choose Operation - 1)Set 2)Clear 3)Update" << endl;
    int option;
    cin >> option;

    int mask;
    int clearBitNumber;

    switch (option) {
        case 1:
            // set the bit i.e make it 1
            mask = (1 << i);
            num = num | mask;
            cout<<num;
            break;
        case 2:
            // make all bits 1 except ith one and then do and operation w num
            mask = ~(1 << i);
            num = num & mask;
            cout << num;
            break;
        case 3:
            cout << "Enter the bit to be set" << endl;
            int bit;
            cin >> bit;
            clearBitNumber = num & (~(1 << i));
            cout << (clearBitNumber | (bit << i)) << endl;
            break;
        default:
            cout<<"Error"<<endl;
            break;
    }
    return 0;
}