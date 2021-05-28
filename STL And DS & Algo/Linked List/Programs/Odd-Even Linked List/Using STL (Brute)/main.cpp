// program to arrange elements in linked list such that all the even elements appear after the odd elements

#include<list>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    list<int> l;
    int data;
    for (int i = 0; i < n; i++) {
        cin >> data;
        l.emplace_back(data);
    }
    // 1 2 2 2 1 -> 1 1 2 2 2
    for (auto i = l.begin(); i!=l.end(); i++) {
        if (*i % 2 != 0) {
            // means the element is odd
            int temp = *i;
            i = l.erase(i);
            l.push_front(temp);
        }
    }

    for(auto i: l)
        cout<<i<<" ";
}
