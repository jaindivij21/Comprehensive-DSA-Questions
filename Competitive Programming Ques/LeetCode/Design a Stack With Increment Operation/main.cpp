// Leetcode: Design a Stack With Increment Operation
// https://leetcode.com/problems/design-a-stack-with-increment-operation

#include <iostream>
#include <deque>

using namespace std;

class CustomStack
{
private:
  int maxSize;
  deque<int> stack;

public:
  // Constructor
  explicit CustomStack(int maxSize) : maxSize(maxSize) {}

  // Method to push an element onto the stack
  void push(int x)
  {
    // Check if the stack has reached its maximum size
    if (stack.size() == maxSize)
      return; // Do nothing if the stack is full

    // Add the element to the front of the deque (top of the stack)
    stack.push_front(x);
  }

  // Method to pop an element from the stack
  int pop()
  {
    // Check if the stack is empty
    if (stack.empty())
      return -1;

    // Get the top element from the front of the deque and pop it
    int top = stack.front();
    stack.pop_front();

    return top;
  }

  // Method to increment the bottom k elements by a given value
  void increment(int k, int val)
  {
    // Loop through the bottom k elements, considering the size of the stack
    for (int i = 0; i < k && i < stack.size(); i++)
    {
      // Increment the element at the position (stack.size() - 1 - i)
      // This effectively accesses the bottom k elements from the front
      stack[stack.size() - 1 - i] += val;
    }
  }
};

int main()
{
  auto *obj = new CustomStack(3);
  obj->push(5);
  int param_2 = obj->pop();
  obj->increment(2, 100);
  delete (obj);

  return 0;
}