// Make Stack Data Structure : LIFO

#include <bits/stdc++.h>

using namespace std;

// STL Stack Class: Push, Pop, Peek(Top), ifEmpty
class Stack1
{
    vector<int> stack;

public:
    void push(int ele)
    {
        stack.push_back(ele);
    }

    void pop()
    {
        if (!stack.empty())
            stack.pop_back();
    }

    int peek()
    {
        return stack[stack.size() - 1];
    }

    bool ifEmpty()
    {
        if (stack.empty())
            return true;
        else
            return false;
    }
};

int main()
{

    return 0;
}