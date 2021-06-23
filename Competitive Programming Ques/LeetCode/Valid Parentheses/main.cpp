// Valid Parentheses :: Leetcode
// https://leetcode.com/problems/valid-parentheses/

#include<bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack<char> stack;
    for (char &i : s) {
        if (i == '(' || i == '{' || i == '[')
            stack.push(i);
        else {
            char c;
            if (!stack.empty())
                c = stack.top();
            else
                c = '*';
            if (i == ')' && c == '(' || i == ']' && c == '[' || i == '}' && c == '{') {
                stack.pop();
                continue;
            } else {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    string s;
    cin >> s;
    bool ans = isValid(s);
    cout << ans;

    return 0;
}