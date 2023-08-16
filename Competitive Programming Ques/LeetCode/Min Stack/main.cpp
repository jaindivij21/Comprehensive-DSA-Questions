// Leetcode: Min Stack
// https://leetcode.com/problems/min-stack/description/

#include <vector>

using namespace std;

// Stack Class to keep track of the least value of the stack.
class MinStack {
private:
    // Using vector of pairs to represent our stack: In the pair, first element is the normal stack element,
    // whilst the second element is the least value in the stack till that element.
    vector<pair<int, int> > stack;
public:
    MinStack() = default;

    // Push into the stack
    void push(int val) {
        int minValTillNow = val;
        if (!stack.empty()) {
            minValTillNow = getMin();
        }

        stack.emplace_back(val, min(val, minValTillNow));
    }

    // Pop from the stack
    void pop() {
        stack.pop_back();
    }

    // Return the top most element from the stack
    int top() {
        return stack.back().first;
    }

    // Return the least element in the stack
    int getMin() {
        return stack.back().second;
    }
};

int main() {

    return 0;
}