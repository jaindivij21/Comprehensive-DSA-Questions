// Stacks - LIFO ORDER
// Last in first out

// STL implementation

#include<iostream>
#include<stack>

using namespace std;

int main() {
    stack<int> s;

    // push operation
    for (int i = 1; i <= 5; i++)
        s.push(i * i);

    // pop,empty and top operation
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}

