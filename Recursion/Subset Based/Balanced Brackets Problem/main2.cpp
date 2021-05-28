// generating brackets
#include<iostream>

using namespace std;

void generate(int pairs, string output, int open, int close) {
    // base case
    if (output.length() == 2 * pairs) {
        // means the output is printable
        cout << output << endl;
        return;
    }
    // recursive
    if (open < pairs) {
        // means more open brackets are possible
        output.append("(");
        generate(pairs, output, open + 1, close);
        output.pop_back();  // STATEMENT
    }
    if (close < open) {
        // means more close brackets are possible
        output.append(")");
        generate(pairs, output, open, close + 1);
    }
}

int main() {
    int pairs;
    cin >> pairs;

    string output;
    int noOfOpenBrackets = 0;
    int noOfCloseBrackets = 0;
    generate(pairs, output, noOfOpenBrackets, noOfCloseBrackets);
    return 0;
}
