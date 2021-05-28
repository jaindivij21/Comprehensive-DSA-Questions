//  Queue - FIFO Order
// First in first out

// Implementation using a vector - Helps to make unlimited sized queue as vector keeps on increasing dynamically
// Not efficient as the circular queue since takes up quite a lot of space

// only useful when you dont know the amount of  elements the queue is going to have (dynamic)

#include<iostream>
#include<vector>

using namespace std;

class Queue {
private:
    vector<int> v;
public:
    bool empty() {
        // if empty or not
        return v.empty();
    }

    int peek() {
        // return the front most (top element)
        return v.front();
    }

    void push(int data) {
        // push data at the rear end (backend)
        v.push_back(data);
    }

    void pop() {
        // pop's elements from the start (front)
        if(!v.empty())
            v.erase(v.begin());
    }

    int count() {
        return v.size();
    }

    void display() {
        // prints the queue
        for (auto i:v)
            cout << i << " ";
        cout << endl;
    }
};

int main() {
    Queue q;

    int size;
    cout << "Enter the size of the queue" << endl;
    cin >> size;

    cout << "Empty?" << q.empty() << endl;

    for (int i = 1; i <= size; i++) {
        q.push(i);
    }
    q.display();
    q.pop();
    q.pop();
    q.push(21);
    cout << "The number of elements in queue are: " << q.count() << endl;
    q.display();
    return 0;
}