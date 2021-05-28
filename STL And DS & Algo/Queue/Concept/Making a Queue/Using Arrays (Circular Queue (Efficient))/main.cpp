/// Queue
// Linear Data Structure - First in First Out (FIFO)
// Using Vectors

#include <iostream>

using namespace std;

class Queue {
private:
    int *arr;
    int front, rear, currSize, maxSize;

public:
    Queue() {
        // constructor
        // make the default queue of size 5
        arr = new int[5];
    }

    Queue(int size) {
        // constructor
        arr = new int[size];
        currSize = 0;
        maxSize = size;
        front = 0;
        rear = maxSize - 1;
    }

    bool full() const {
        // if the queue is full
        return currSize == maxSize;
    }

    bool empty() const {
        // if the queue is empty
        return currSize == 0;
    }

    void push(int data) {
        // pushes the element (push always happen at rear end)
        if (!full()) {
            rear = (rear + 1) % maxSize;
            arr[rear] = data;
            currSize++;
        } else {
            cout << "Error! The queue is full/Overflow" << endl;
        }
    }

    void pop() {
        // pop the element (first element is popped (front element))
        if (!empty()) {
            front = (front + 1) % maxSize;
        } else {
            cout << "Error! The queue is empty/Underflow" << endl;
        }
    }

    int peek() {
        // returns the front element
        if (!empty())
            return arr[front];
        else {
            cout << "Error! Queue is empty!" << endl;
            return -1;
        }
    }

    int count() const {
        // returns the number of elements in queue
        return rear - front + 1;
    }

    void display() {
        cout << "\nQueue:" << endl;
        for (int i = front; i != rear; i = (i + 1) % maxSize) {
            cout << arr[i] << " ";
        }
        cout << arr[rear];
        cout << endl;
    }

    ~Queue() {
        // destructor
        if (arr != nullptr) {
            // means arr points to something
            delete[] arr;
            arr = nullptr;
        }
    }
};

int main() {
    cout<<"Enter the size of the queue"<<endl;
    int size;
    size = 4;   // hardcoded
    // cin>>size;
    Queue q(size);
    cout << "Empty?" << q.empty() << endl;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << "Full?" << q.full() << endl;
    q.push(5);

    q.display();

    q.pop();    // 1 should pop
    q.pop();    // 2 should pop
    cout << "The number of elements in queue are: " << q.count() << endl;
    q.display();

    return 0;
}














