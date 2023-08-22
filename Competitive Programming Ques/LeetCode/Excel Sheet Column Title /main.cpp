// Leetcode: Excel Sheet Column Title
// https://leetcode.com/problems/excel-sheet-column-title/
// https://www.youtube.com/watch?v=UcTKk2y_3s4&ab_channel=KnowledgeCenter

#include<iostream>

using namespace std;

char getAlphabet(int num) {
    return static_cast<char>('A' + (num - 1) % 26);
}

string convertToTitle(int columnNumber) {
    string ans;
    while (columnNumber > 0) {
        ans = getAlphabet(columnNumber) + ans;
        columnNumber = (columnNumber - 1) / 26;
    }

    return ans;
}

int main() {
    int num;
    cin >> num;

    cout << convertToTitle(num);

    return 0;
}