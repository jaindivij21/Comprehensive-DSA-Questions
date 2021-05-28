// vector of stacks

#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
    // size of vector already known (no of stacks known)

    vector<stack<int>> v(2);
    v[0].push(5);
    v[0].push(10);
    v[1].push(1);
    v[1].push(2);

    // if the vector size isn't known already

    vector<stack<int>> s;
    // declare the stack at vector index before initializing it
    s.emplace_back(stack<int>());
    s[0].push(5);
    s.emplace_back(stack<int>());
    s[1].push(10);


    return 0;
}