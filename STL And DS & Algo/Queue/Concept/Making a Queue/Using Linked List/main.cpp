// Queue - FIFO
// Implementation of a queue using linked list

// Linked list allows the queue to be dynamic i.e. no need to specify the queue size beforehand


#include<iostream>

using namespace std;

// node class
class node {
public:
    int data;
    node *next;

    node(int d) {
        data = d;
        next = nullptr;
    }
};

// queue class
class queue {
private:
    node *front = nullptr;
    node *rear = nullptr;
public:
    bool empty() {
        // if empty or not
        return front == nullptr;
    }

    int peek() {
        // return the front/top element
        return front->data;
    }

    int count() {
        // prints the length/size of the queue
        int count = 0;
        node *itr = front;
        while (itr != rear->next) {
            itr = itr->next;
            count++;
        }
        return count;
    }

    void display() {
        cout << "Queue: " << endl;
        node *itr = front;
        while (itr != rear->next) {
            cout << itr->data << " ";
            itr = itr->next;
        }
        cout << endl;
    }

    void push(int d) {
        // insertion always at the rear end
        if (front == nullptr) {
            // first insertion
            front = rear = new node(d);
        } else {
            // insertion at the tail
            node *temp = new node(d);
            rear->next = temp;
            rear = temp;
        }
    }

    int pop() {
        int x;
        // deletion in a queue always happens at the front
        if (front == nullptr) {
            // queue is already empty
            cout << "Underflow error! Queue already empty" << endl;
        } else {
            node *temp = front;
            x = temp->data;
            front = front->next;
            delete temp;
        }
        return x;
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
    cout << "Popping:" << q.pop() << endl;
    cout << "The top most element of the queue is: " << q.peek() << endl;

    // random operations
    cout << "Popping:" << q.pop() << endl;
    cout << "Popping:" << q.pop() << endl;

    q.push(21);
    q.display();
    return 0;
}