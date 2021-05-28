// String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

#include<bits/stdc++.h>

using namespace std;

pair<int, int> limits() {
    long int x = 1;
    for (int i = 1; i <= 31; i++)
        x *= 2;
    return make_pair(x - 1, -1 * (x));
}

int myAtoi(string s) {
    long long int ans = 0;
    bool isNegative = false;
    pair<int, int> p = limits();

    int flag = false;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            flag = true;
            if (i - 1 >= 0 && s[i - 1] == '-') {
                isNegative = true;
            }
        }
        if (flag) {
            // if flag is true we start making the number and stop as soon as it becomes false
            if (!isdigit(s[i])) {
                flag = false;
                break;
            }
            // else add into construction of the number
            int num = s[i] - '0';
            ans *= 10;
            ans += num;
        }
        if (!flag)
            continue;
    }

    if (isNegative)
        ans *= -1;
    if (ans < p.second)
        return INT_MIN;
    else if (ans > p.first)
        return INT_MAX;
    else {
        return ans;
    }
}

int main() {
    string str;
    getline(cin, str);

    int ans = myAtoi(str);
    cout << ans;

    return 0;
}