// Balanced Parenthesis Problem
// STACKS

#include<iostream>
#include<stack>

using namespace std;

// main function
bool isValid(char *s) {
    stack<int> p;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(')
            p.push(s[i]);
        else if (s[i] == ')') {
            if (p.empty() or p.top() != '(')
                return false;
            p.pop();
        } else
            continue;
    }
    // if the stack is empty retrun true else false
    return p.empty();
}

int main() {
    cout << "Enter the string whose balanced parenthesis" << endl;
    char str[100];
    cin >> str;

    bool ans = isValid(str);
    if (ans)
        cout << "Yes it's valid" << endl;
    else
        cout << "No, it isn't valid" << endl;

    return 0;
}