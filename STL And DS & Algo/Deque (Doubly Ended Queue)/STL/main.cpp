// Deque: A linear data structure very similar to vectors but with added functionality of linked lists that help it to expand from both front and end

#include <iostream>
#include <deque>

using namespace std;

void showdq(deque<int> g) {
    deque<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << " ";
    cout << '\n';
}

int main() {
    deque<int> deq;

    // functionality to add at front and back both *(linked list)
    deq.push_back(10);
    deq.push_front(20);
    deq.push_back(30);
    deq.push_front(15);
    cout << "The deque is : ";
    showdq(deq);

    cout << "deq.size() : " << deq.size() << endl;
    cout << "deq.max_size() : " << deq.max_size() << endl;

    // functionality of random access *(array/vector)
    cout << "deq.at(2) : " << deq.at(2) << endl;
    cout << "deq.front() : " << deq.front() << endl;
    cout << "deq.back() : " << deq.back() << endl;

    cout << "deq.pop_front() : " << endl;
    deq.pop_front();
    showdq(deq);

    cout << "deq.pop_back() : ";
    deq.pop_back();
    showdq(deq);

    return 0;
} 
