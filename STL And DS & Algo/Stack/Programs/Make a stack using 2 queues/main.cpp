// Implement a stack using 2 queues
// Implement LIFO using 2 FIFOs

#include<iostream>
#include<queue>

using namespace std;

// making a generic stack class
template<typename T>
class stack {
private:
    // 2 queues
    queue<T> q1;
    queue<T> q2;
public:
    void push(int data) {
        // cheap operation (O(1))
        q1.push(data);
    }

    void pop() {
        // expensive operation (O(n))
        // move first n-1 elements in q2, then pop the element left in q1, then interchange the names of the queues
        if (q1.empty()) {
            return;
        } else {
            while (q1.size() > 1) {
                // runs till the size is 1 i.e. only one element left in the queue
                q2.push(q1.front());
                q1.pop();
            }
            // now only one last element left in q1 which can be popped
            q1.pop();
            // interchange the names of the queues
            // queue<T> temp = q1;
            // q1 = q2;
            // q2 = temp;
            swap(q1, q2);
        }
    }

    T top() {
        while (q1.size() > 1) {
            // runs till the size is 1 i.e. only one element left in the queue
            q2.push(q1.front());
            q1.pop();
        }
        // now only one last element left in q1 which can be popped and returned but remember,
        // this element popped must also be pushed into the queue2
        T element = q1.front();
        q2.push(element);    // IMPORTANT
        q1.pop();
        // interchange names
        swap(q1, q2);
        return element;
    }

    int size() {
        return q1.size() + q2.size();
    }

    bool empty() {
        return size() == 0;
    }
};

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}