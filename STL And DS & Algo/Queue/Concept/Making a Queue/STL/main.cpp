// Queue STL

#include<iostream>
#include <queue>

using namespace std;

int main() {
    // CHECK BY DEBUGGING
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;
    q.pop();

    cout << q.empty() << endl;

    return 0;
}