// Heaps
// Priority Queue: STL

#include<iostream>
#include<queue>

using namespace std;

int main() {
    // declare priority queue
    // IMPORTANT: BY DEFAULT THE maxHeap IS MAX HEAP
    priority_queue<int> maxHeap;

    // TO MAKE THE MIN HEAP :: here the third parameter is class object of Compare class
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int a[10] = {5, 6, 17, 18, 9, 11};

    // insert into maxHeap
    for (int i = 0; i < 10; i++) {
        maxHeap.push(a[i]);
    }
    // insert into minHeap
    for (int i = 0; i < 10; i++) {
        minHeap.push(a[i]);
    }

    // while the maxHeap isn't empty, print the top element and then pop or delete the top element
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }

    cout << endl;

    // while the minHeap isn't empty, print the top element and then pop or delete the top element
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }

    return 0;
}