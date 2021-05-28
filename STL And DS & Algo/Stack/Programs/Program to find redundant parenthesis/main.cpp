// Duplication of balanced parenthesis
// https://www.youtube.com/watch?v=aMPXhEdpXFA

#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

bool findRed(string str) {
    stack<int> s;
    for (char temp : str) {
        // push if you get opening brackets or any other characters
        if (temp != ')') {
            s.push(temp);
        } else {
            if (s.top() == '(') {
                return true;
            } else {
                while (s.top() != '(') {
                    s.pop();
                }
                s.pop();
            }
        }
    }
    return false;
}


int main() {
    // for all the test cases
    int testCases;
    cin >> testCases;
    while (testCases--) {
        // input the string
        string str;
        cin >> str;

        bool ans = findRed(str);

        if (ans)
            cout << "Duplicate" << endl;
        else
            cout << "Not Duplicates" << endl;
    }

    return 0;
}