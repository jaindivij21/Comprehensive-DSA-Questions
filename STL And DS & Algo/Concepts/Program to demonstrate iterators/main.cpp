// Program to demonstrate iterators
#include <iostream>
#include <set>

using namespace std;


int main() {
    set<int> s;
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(3);

    // Method to iterate over each set member
    for (auto x:s) {
        // cout<<x <<endl;
    }

    // Iterators are like pointers
    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        cout << (*it) << endl;
    }

    return 0;
}