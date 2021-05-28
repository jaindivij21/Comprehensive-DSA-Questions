// Finding K largest elements in a running stream
// 'Running Stream' means we cannot store all the numbers
// Find at any moment the largest k numbers

#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int>> pq) {
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main() {
// SOLUTION 1 : using a MAX HEAP but here we are storing all the elements which isn't allowed. So use Solution 2
/*
    // since we cannot store the numbers we'll use heap
    priority_queue<int> pq; // max heap

    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;

    int input;
    cin >> input;
    while (input != -1) {
        if (input == 0) {
            // means output the largest k elements
            for (int i = 0; i < k; i++) {
                cout << pq.top()<<" ";
                pq.pop();
            }
            break;
        }
        pq.push(input);
        cin >> input;
    }
*/

// SOLUTION 2 : using a MIN HEAP and storing only 3 largest elements i.e. if get a larger element we replace it with the top most or smallest element
// TC: O(NlogK)
    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int input;
    // take the input till the end of file
    while (scanf("%d", &input) != EOF) {
        if (input == -1) {
            // print the top 3 elements
            printHeap(pq);  // pass by value and not reference since we dont want to change it
        } else if (pq.size() < k) {
            // if the size of the heap is less than k then keep pushing the elements
            pq.push(input);
        } else {
            // once the size of heap is equal to k, then we need to keep the max elements in the heap
            if (pq.top() < input) {
                pq.pop();
                pq.push(input);
            }
        }
    }

    return 0;
}

