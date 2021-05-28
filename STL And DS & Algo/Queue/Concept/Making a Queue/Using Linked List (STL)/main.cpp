// Queue - FIFO
// Implementation of a queue using linked list

// Linked list allows the queue to be dynamic i.e. no need to specify the queue size beforehand


#include<iostream>
#include<list>

using namespace std;

class queue {
private:
    int currSize;
    list<int> q;
public:
    queue() {
        currSize = 0;
    }

    bool empty() const {
        return currSize == 0;
    }

    void push(int data) {
        q.push_back(data);
        currSize++;
    }

    void pop() {
        if (!empty()) {
            q.pop_front();
        }
    }

    int peek() {
        return q.front();
    }

    int count() {
        return q.size();
    }

    void display() {
        for (auto i:q) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    // size
    cout << "Enter the initial number of elements in the queue" << endl;
    int size;
    cin >> size;

    // initial queue
    queue q;
    cout << "Enter the initial elements of the queue" << endl;
    for (int i = 0; i < size; i++) {
        int d;
        cin >> d;
        q.push(d);
    }

    // print
    q.display();
    // size
    cout << "The size of the queue is:" << q.count() << endl;

    // pop
    q.pop();
    cout << "The top most element of the queue is: " << q.peek() << endl;

    // random operations
    q.pop();
    q.pop();

    q.push(21);
    q.display();
    return 0;
}