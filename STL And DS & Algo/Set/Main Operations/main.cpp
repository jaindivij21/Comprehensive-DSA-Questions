// Set Data Structure

#include<iostream>
#include<set>

using namespace std;

int main() {
    int arr[] = {10, 20, 11, 9, 8, 11, 10};
    int size = sizeof(arr) / sizeof(int);

    set<int> s;
    for (int i = 0; i < size; i++) {
        s.insert(arr[i]);
    }

    auto itr = s.find(11);
    s.erase(itr);

    for (set<int>::iterator itr = s.begin(); itr != s.end(); itr++) {
        cout << (*itr) << " ";
    }
    cout << endl;
    
    return 0;
}
