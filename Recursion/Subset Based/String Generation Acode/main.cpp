// generate string program
// Using Recursion

// given a number like 1234, print all possible string that can be generated considering:
// 1 - A, 2- B, ..... 12-L......26-Z

#include <iostream>
#include<cstring>

using namespace std;

void generationStrings(char inp[], char out[], int i, int j) {
    // base case
    if (inp[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive
    // one digit at a time
    int digit = inp[i] - '0';
    char ch = digit + 'A' - 1; // make the character
    out[j] = ch;
    generationStrings(inp, out, i + 1, j + 1);

    // two digits at a time
    // next digit shouldn't be null
    if (inp[i + 1] != '\0') {
        int secondDigit = inp[i + 1] - '0';
        int no = digit * 10 + secondDigit;
        // make sure this number is less than 26
        if (no <= 26) {
            ch = no + 'A' - 1;
            out[j] = ch;
            generationStrings(inp, out, i + 2, j + 1);
        }
    }
    return;
}

int main() {
    cout << "Enter the string of number" << endl;
    char a[100];
    cin >> a;

    char out[100];
    generationStrings(a, out, 0, 0);

    return 0;
}
