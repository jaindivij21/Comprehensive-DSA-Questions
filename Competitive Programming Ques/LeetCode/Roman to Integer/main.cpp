// Roman to integer: Leetcode
// https://leetcode.com/problems/roman-to-integer/

#include<bits/stdc++.h>

using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> roman = {{'I', 1},
                                      {'V', 5},
                                      {'X', 10},
                                      {'L', 50},
                                      {'C', 100},
                                      {'D', 500},
                                      {'M', 1000}};

    int sum = 0;
    int i = 0;
    for (i = 0; i < s.length() - 1; i++) {
        if (roman.at(s[i]) < roman.at(s[i + 1])) {
            sum += (roman.at(s[i + 1]) - roman.at(s[i]));
            i++;
        } else {
            sum += roman.at(s[i]);
        }
    }
    if (i == s.length() - 1) {
        sum += roman.at(s[i]);
    }
    return sum;
}

int main() {
    string str;
    cin >> str;
    int ans = romanToInt(str);

    cout << ans << endl;

    return 0;
}