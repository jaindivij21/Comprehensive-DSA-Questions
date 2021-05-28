// Generate Brackets Strings Problem
// Using Recursion
// Given a number N, generate BALANCED BRACKETS using n pairs of Round Brackets

#include<iostream>

using namespace std;

// recursive function
// open = open brac ; close = close brac
void generateBrackets(char output[], int noOfPairs, int idx, int open, int close) {
    // base case
    if (idx == 2 * noOfPairs) {
        output[idx] = '\0';
        cout << output << endl;
        return;
    }
    // adding brackets (recursive)
    // 2 ways in the middle of the string
    if (open < noOfPairs) {
        output[idx] = '(';
        generateBrackets(output, noOfPairs, idx + 1, open + 1, close);
    }
    if (close < open) {
        output[idx] = ')';
        generateBrackets(output, noOfPairs, idx + 1, open, close + 1);
    }
    return;
}

int main() {
    // input
    int n;
    cout << "Enter the number of pairs of round brackets" << endl;
    cin >> n;

    // make an output string
    char output[1000];

    generateBrackets(output, n, 0, 0, 0);

    return 0;
}


