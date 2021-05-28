// Stack class with push, pop, top and MIN-MAX functions
// Will be done using 3 stacks

#include<iostream>
#include<vector>

using namespace std;

class Stack {
private:
    vector<int> stack;
    vector<int> minStack;
    vector<int> maxStack;
public:
    Stack() = default;

    void push(int data) {
        stack.push_back(data);
        if (maxStack.empty() && minStack.empty()) {
            // means the min and max stack are empty
            // means we are inserting the first element
            maxStack.push_back(data);
            minStack.push_back(data);
        } else {
            // means the stacks have at least one element
            maxStack.push_back(max(data, maxStack[maxStack.size() - 1]));
            minStack.push_back(min(data, minStack[minStack.size() - 1]));
        }
    }

    void pop() {
        stack.pop_back();
        minStack.pop_back();
        maxStack.pop_back();
    }

    bool empty() {
        return stack.empty();
    }

    int getMin() {
        return minStack[minStack.size() - 1];
    }

    int getMax() {
        return maxStack[maxStack.size() - 1];
    }

    int top() {
        return stack[stack.size() - 1];
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);

    cout << "Max: " << s.getMax() << endl;
    s.pop();
    cout << "Min: " << s.getMin() << endl;
    cout << "Max: " << s.getMax() << endl;

    s.pop();
    s.pop();
    cout << "Top: " << s.top() << endl;
    cout << "Max: " << s.getMax() << endl;

    return 0;
}