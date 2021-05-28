// Using bitwise operators clear a range of bits in a number

#include<iostream>

using namespace std;

int clearLast_Pos1_Bits(int num, int i) {
    int mask = ~0 << i;
    return num & mask;
}

int clearRange_pos1_to_pos2(int num, int i, int j) {
    // ex if i = 1 and j = 3
    // for 0011111 -> 0010001 --> mask needed = 1110001
    int allOnes = ~0; // 1111111
    int a = allOnes << (j + 1); // 1110000
    int b = (1 << i) - 1; // 0000001 -> to obtain any number of the form 0000111 etc its = 2^n -1 (and 2^n = 1 << n)
    int mask = a | b;
    return num & mask;
}

int main() {
    cout << "Enter the number" << endl;
    int num;
    cin >> num;
    cout << "Enter the positions" << endl;
    int pos1;
    cin >> pos1;
    int pos2;
    cin >> pos2;

    cout << clearLast_Pos1_Bits(num, pos1) << endl;
    cout << clearRange_pos1_to_pos2(num, pos1, pos2) << endl;


    return 0;
}