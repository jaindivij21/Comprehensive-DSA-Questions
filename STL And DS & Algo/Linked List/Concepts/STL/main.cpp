// Demonstrate the use of List using STL

#include<iostream>
#include<list>  // doubly linked list
#include<forward_list>  // singly linked list

using namespace std;

// generic print function
template<typename T>
void print(list<T> l) {
    for (auto item:l) {
        cout << item << " -> ";
    }
    cout << endl;
}

int main() {
    list<int> l1;
    list<int> l2{1, 2, 3};
    list<string> l3{"apple", "mango"};
    l3.push_back("banana");

    print(l3);

    l3.sort();
    print(l3);

    l3.reverse();
    print(l3);

    l3.push_front("Kiwi");
    l3.pop_back();
    print(l3);

    cout << l3.back() << endl;

    // instead of using auto, can use iterators also to iterate over the list
    for (auto it = l3.begin(); it != l3.end(); it++) {
        cout << (*it) << " -> ";
    }
    cout << endl;

    l3.push_back("orange");
    l3.push_back("lemon");
    print(l3);

    // remove a specific fruit
    string fruitToRemove;
    cout << "Enter the fruit to remove" << endl;
    cin >> fruitToRemove;
    l3.remove(fruitToRemove);
    print(l3);

    // erase an element at a specific index
    // for this iterators have to be passed into erase function
    auto itr = l3.begin();
    advance(itr, 2);    // advances the iterator by 2
    l3.erase(itr);  // erases that index/ that iterator (index 2)

    // insert element into the list
    //    itr = l3.begin();
    //    advance(l3,1);
    //    l3.insert(itr,"Fruit Juice");

    // array of lists
    list<int> l4[5];    // static
    
    // dynamic 
    list<int> *l5;
    int size;
    cin>>size;
    l5 = new list<int>[size];

    return 0;
}