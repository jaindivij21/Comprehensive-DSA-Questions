#include <iostream>
#include<cstring>

using namespace std;
char keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

// main function;; i and j respectively are iterators for the input and output strings
void printkeys(char inp[], char out[], int i, int j) {
    //base case
    if (inp[i] == '\0') {
        // if you reach the end of input string, end the output string and print it
        out[j] = '\0';
        cout << out << ",";
        return;
    }

    //rec case
    
    // extract last digit
    int digit = inp[i] - '0';
    
    // candle corner cases
    if (digit == 1 || digit == 0) {
        printkeys(inp, out, i + 1, j);
    }

    // loop for each alphabet for each digit
    for (int k = 0; keypad[digit][k] != '\0'; k++) {
        // for each alphabet recursively call for the remaining places
        out[j] = keypad[digit][k];
        printkeys(inp, out, i + 1, j + 1);
    }

}

int main() {
    char inp[100];
    char out[100];
    cin >> inp;
    printkeys(inp, out, 0, 0);
}
