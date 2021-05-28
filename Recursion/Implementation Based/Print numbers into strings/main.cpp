// Convert numbers to Strings (Spellings)
// USE RECURSION
// Ex. 2048 - two zero four eight

#include<iostream>
#include<string>

using namespace std;

// global array of strings wrt to indexes
// string words[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char words[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void spell(int num) {
    // base case
    if (num == 0)
        return;
    else {
        spell(num / 10);
        int numberat = num % 10;
        cout << words[numberat] << " ";
        return;
    }
}

int main() {
    int num;
    cout << "Enter the number" << endl;
    cin >> num;

    spell(num);

    return 0;
}