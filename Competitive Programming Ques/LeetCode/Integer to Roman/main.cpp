
#include<bits/stdc++.h>

using namespace std;

string intToRoman(int num) {
    string result;
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string rom[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int i = 0;
    while (num != 0) {
        while (num >= val[i]) {
            num -= val[i];
            result.append(rom[i]);
        }
        i++;
    }
    return result;
}

int main() {
    int num;
    cin >> num;
    string ans = intToRoman(num);

    cout << ans << endl;

    return 0;
}