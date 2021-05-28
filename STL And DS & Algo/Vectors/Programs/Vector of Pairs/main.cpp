// Program to demonstrate a vector of pairs
#include <iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

// unused func (comparator function to sort acc to string length)
bool myComp(pair<string, int> p1, pair<string, int> p2) {
    if (p1.first.length() == p2.first.length()) {
        return p1.first > p2.first;
    }
    return p1.first.length() < p2.first.length();

}

// comparator func to sort acc to ascending price
bool priceComp(pair<string, int> p1, pair<string, int> p2) {
    return p1.second < p2.second;
}

// main functions
int main() {
    // vector of pairs
    vector<pair<string, int> > v;

    int n;
    cin >> n;

    // make the vector
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int p;
        cin >> p;
        pair<string, int> myPair(s, p);
        v.push_back(myPair);
    }
    // sort the vector acc to comparator functions
    sort(v.begin(), v.end(), priceComp);

    // print the vectors
    for (auto p:v) {
        cout << p.first << " : " << p.second << endl;
    }


    return 0;
}
