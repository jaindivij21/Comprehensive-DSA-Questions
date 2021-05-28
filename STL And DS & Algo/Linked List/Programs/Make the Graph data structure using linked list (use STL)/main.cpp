// Implementing a graph using a list
// Most important application of linked list
// Graph is nothing but an ARRAY OF LISTS

#include<iostream>
#include<list>

using namespace std;

int main() {
    // static declaration
    // list<pair<int, int>> l[5];
    /*
     *  it basically says that you wanna make a graph with 5 nodes. i.e an an array of lists,
     *  with 5 lists. each list contains pairs(of int int)
     */

    // dynamic declaration
    list<pair<int, int>> *l;
    // input nodes
    int n;
    cout << "Enter the number of nodes" << endl;
    cin >> n;

    // create the array of lists
    l = new list<pair<int, int>>[n];

    // input the number of edges
    int e;
    cout << "Enter the numebr of edges" << endl;
    cin >> e;

    // input the adjacencey list
    for (int i = 0; i < e; i++) {
        int x, y, wt;
        cin >> x >> y >> wt;
        l[x].push_back(make_pair(y, wt));
        l[y].push_back(make_pair(x, wt));
    }

    // print the output lists
    for (int i = 0; i < n; i++) {
        cout << "linked list" << i << "-->";
        for (auto pair:l[i]) {
            cout << "(" << pair.first << "," << pair.second << "),";
        }
        cout << endl;
    }
    return 0;
}
