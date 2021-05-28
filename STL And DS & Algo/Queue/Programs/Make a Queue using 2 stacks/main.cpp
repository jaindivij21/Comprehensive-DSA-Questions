// Implement a queue using 2 stacks
// Implement FIFO using 2 LIFO

#include<iostream>
#include<stack>

using namespace std;

// making a generic stack class
template<typename T>
class queue {
private:
    stack<T> s1;
    stack<T> s2;
public:
    bool empty() {
        if (s1.empty()) {
            return true;
        } else
            return false;
    }

    void push(int data) {
        // push the data into 1st stack
        s1.push(data);
    }

    void pop() {
        // check if the stack is already empty
        if (!s1.empty()) {
            // run a loop for popping n-1 elements and shifting them to stack 2
            while (s1.size() > 1) {
                s2.push(s1.top());
                s1.pop();
            }
            // for the last element just pop it
            s1.pop();

            // now we need to bring back the stack 2 elements to stack 1
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    T peek() {
        while (s1.size() > 1) {
            // run a loop for popping n-1 and shifting them to stack 2
            s2.push(s1.top());
            s1.pop();
        }
        // for the last element just pop it and also push in stack 2
        T element = s1.top();
        s2.push(element);
        s1.pop();
        
        // now we need to bring back the stack 2 elements to stack 1
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return element;
    }
};

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while (!q.empty()) {
        cout << q.peek() << " ";
        q.pop();
    }

    return 0;
}