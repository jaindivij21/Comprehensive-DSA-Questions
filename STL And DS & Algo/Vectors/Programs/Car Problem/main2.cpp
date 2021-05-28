// Car Problem
// Given the coordinates of cabs, find and sort their distance form origin
// Information about the car can be stored either in form of a class or in form of pair of vectors

// CLASS

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

class Car {
public:
    string name;
    int x, y;

    Car() {

    }

    Car(string n, int a, int b) {
        name = n;
        x = a;
        y = b;
    }

    // methods
    int disFromOrigin() {
        return x * x + y * y;
    }

};

bool compare(Car a, Car b) {
    int d1 = a.disFromOrigin();
    int d2 = b.disFromOrigin();
    if (d1 == d2) {
        // lexographic sorting
        return a.name < b.name;
    }
    return d1 < d2;
}


int main() {
    // number of cars
    cout << "Enter the number of cars" << endl;
    int n;
    cin >> n;

    vector<Car> v;
    for (int i = 1; i <= n; i++) {
        string name;
        cout << "Enter the name of car " << i << " :";
        cin >> name;
        int x, y;
        cout << "Enter the coordinates of car " << i << " :";
        cin >> x >> y;

        // make the car object
        Car *obj = new Car(name, x, y);
        v.emplace_back(*obj);
    }

    // sort them based on the distance
    sort(v.begin(), v.end(), compare);

    for (auto i:v) {
        cout << "Car " << i.name << ":" << i.disFromOrigin() << endl;
    }

    return 0;
}