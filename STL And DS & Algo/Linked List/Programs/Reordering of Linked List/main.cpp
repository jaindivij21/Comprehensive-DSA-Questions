// Reordering of linked list
/*
 *  Given a linked list of length N and an integer K ,
 *  append the last K elements of a linked list to the front. Note that K can be greater than N.
 *
 *  Sample Input
 *  7
 *  1 2 2 1 8 5 6
 *  3
 *
 *  Sample Output
 *  8 5 6 1 2 2 1
 */

#include<iostream>
#include<list>

using namespace std;

int main() {
    // input size
    int size;
    cin >> size;

    // make and input the list
    list<int> head;
    int element;
    for (int i = 0; i < size; i++) {
        cin >> element;
        head.emplace_back(element);
    }

    // input the value of k
    int k;
    cin >> k;

    while (k--) {
        int x = head.back();
        head.pop_back();
        head.push_front(x);
    }

    for (auto item:head)
        cout << item << " ";

    return 0;
}