// Stacks - LIFO ORDER
// Last in first out

// Implementation using array (vector)
// When stack needs to have limited size and less space

#include<iostream>
#include<vector>

using namespace std;

class Stack {
private:
    vector<int> v;
public:
    void push(int data) {
        v.push_back(data);
    }

    void pop() {
        if (!v.empty())
            v.pop_back();
    }

    bool empty() {
        if (v.empty())
            return true;
        else
            return false;
    }

    int top() {
        return v[v.size() - 1];
    }

};

using namespace std;

int main() {
    Stack s;

    int size;
    cout << "Enter the size of the stack" << endl;
    cin >> size;

    // input data
    for (int i = 0; i < size; i++) {
        int data;
        cin >> data;
        s.push(data);
    }

    cout << endl;

    // print data
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }


    return 0;
}