// Balanced Parenthesis Problem

#include<iostream>
#include<stack>

using namespace std;

int main() {
    // input the string
    string str;
    cin >> str;

    // stack
    stack<char> s;

    for (char temp : str) {
        if (temp == '(' || temp == '{' || temp == '[') {
            s.push(temp);
        } else if (temp == ')' && !s.empty()) {
            if (s.top() == '(') {
                s.pop();
            } else {
                break;
            }
        } else if (temp == '}' && !s.empty()) {
            if (s.top() == '{') {
                s.pop();
            } else {
                break;
            }
        } else if (temp == ']' && !s.empty()) {
            if (s.top() == '[') {
                s.pop();
            } else {
                break;
            }
        } else {
            cout << "Wrong input" << endl;
            exit(-1);
        }
    }
    if (s.empty()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}