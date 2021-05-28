// check by reversing the list and comparing 
// Palindrome in linked lists

#include<iostream>
#include<list>

using namespace std;

int main() {
    list<int> l2;
    list<int> l1;
    int size;
    cin >> size;
    int i = size;
    while (size != 0) {
        int data;
        cin >> data;
        l1.emplace_back(data);
        l2.push_front(data);
        size--;
    }

    auto itr1 = l1.begin();
    auto itr2 = l2.begin();

    while (i--) {
        if (*itr1 != *itr2) {
            cout << "false" << endl;
            return 0;
        }
        advance(itr1,1);
        advance(itr2,1);
    }
    cout << "true" << endl;


    return 0;
}