// Car Problem
// Given the coordinates of cabs, find and sort their distance form origin
// Information about the car can be stored either in form of a class or in form of pair of vectors

// PAIR OF VECTORS

#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

bool sortDistance(pair<int, int> a, pair<int, int> b) {
    int distance1 = a.first * a.first + a.second * a.second;
    int distance2 = b.first * b.first + b.second * b.second;
    if (distance1 == distance2) {
        return a.first < b.first;
    }
    return distance1 < distance2;
}


int main() {
    // number of cars
    cout << "Enter the number of cars" << endl;
    int n;
    cin >> n;

    // store the coordinates of cars
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cout << "Enter the coordinates of car " << i << " :";
        cin >> x >> y;
        v.emplace_back(x, y);
    }

    // sort them based on the distance
    sort(v.begin(), v.end(), sortDistance);

    for (auto i:v) {
        cout << "Car " << i.first << " " << i.second << endl;
    }

    return 0;
}