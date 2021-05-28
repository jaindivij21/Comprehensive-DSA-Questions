// Program to reverse the stack
// USING ONLY ONE EXTRA STACK

#include<iostream>
#include<stack>

using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n) {
    for (int i = 0; i < n; i++) {
        s2.push(s1.top());
        s1.pop();
    }
}

void reverse(int size, stack<int> &s1) {
    // extra stack
    stack<int> s2;

    // for all the elements in the stack
    for (int i = 0; i < size; i++) {
        // save the topmost element
        int temp = s1.top();
        s1.pop();

        // transfer size - i - 1 elements from stack s1 to s2
        transfer(s1, s2, size - i - 1);

        // insert the temp variable back to the stack 1
        s1.push(temp);

        // transfer all the elements back from the stack s2 to s1
        transfer(s2, s1, size - i - 1);
    }
}

void print(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s1;
    int size;
    cin >> size;
    int data;
    for (int i = 0; i < size; i++) {
        cin >> data;
        s1.push(data);
    }
    cout << "Before Reversing: " << endl;
    print(s1);
    reverse(size, s1);
    cout << "After Reversing: " << endl;
    print(s1);
    return 0;
}