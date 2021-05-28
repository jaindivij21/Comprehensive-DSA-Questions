// Phone Keypad Problem
// Using Recursion (Brute Force)

// Given a phone keypad, output all the strings possible when pressed a certain array of numbers

#include<iostream>
#include <cstring>

using namespace std;

// global string/keypad array
string keypad[10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

#include<iostream>

using namespace std;

void generateNames(string in, string out, int i) {
    // if the string is complete print it
    // base case
    if (in[i] == '\0') {
        cout << out << endl;
        return;
    } else {
        // recurisve case
        // extract the digit
        int digit = in[i] - '0';

        // corner cases
        if (digit == 1 || digit == 0) {
            generateNames(in, out, i + 1);
        }

        // run a loop for each of the character for that digit
        for (int j = 0; keypad[digit][j] != '\0'; j++) {
            string s(1, keypad[digit][j]);
            out.append(s);
            // now for each character make a recursive call
            generateNames(in, out, i + 1);
            out.pop_back();
        }
    }
}

int main() {
    string input;
    cout << "Enter the numbers" << endl;
    cin >> input;

    string output;

    // main function
    generateNames(input, output, 0);
    return 0;
}