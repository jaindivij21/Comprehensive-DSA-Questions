// Reverse a stack only using recursion
// http://discuss.codingblocks.com/t/stack-reverse-using-recursion/23407/2
// https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
// https://www.youtube.com/watch?v=8YXQ68oHjAs

#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &s, int x) {
    if (s.empty()) {
        s.push(x);
    } else {
        int y = s.top();
        s.pop();
        insertAtBottom(s, x);
        s.push(y);
    }
}

void reverseStack(stack<int> &s) {
    if (s.empty())
        return;
    else {
        int x = s.top();
        s.pop();
        reverseStack(s);
        insertAtBottom(s, x);
    }
}

int main() {
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(ar[i]);
    reverseStack(s);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}