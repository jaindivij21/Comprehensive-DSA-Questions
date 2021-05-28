// Program to find the k nearest cars from origin, solving using heaps
// Making use of customs comparators and functors because to work with priority queue we need functors********

#include<iostream>
#include<vector>
#include<queue>
#include<functional>

using namespace std;

// class of car
class Car {
public:
    int x;
    int y;
    int id;

    // constructor
    Car(int id, int x, int y) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    // Distance calculator from the origin
    int distance() const {
        return x * x + y * y;
    }

    // print the class object
    void print() const {
        cout << "ID:" << id << ", ";
        cout << "Location:" << x << " " << y << endl;
    }
};

// functor: a class that acts as a function:: functional object
// essential for the use of priority queue as it uses this to compare
class carCompare {
public:
    // method to overload () operator
    bool operator()(Car a, Car b) {
        // for finding the minimum distance cars from origin i.e. maintaining the min heap
        return a.distance() > b.distance();
    }
};

// main function
int main() {
    // make a priority queue of type car class
    priority_queue<Car, vector<Car>, carCompare> pq;    // passing the third parameter as a functor i.e a class that acts like a function

    // Sample x,y coordinates
    int x[10] = {5, 6, 17, 18, 9, 11, 0, 3};
    int y[10] = {1, -2, 8, 9, 10, 91, 1, 2};

    // make class objects
    for (int i = 0; i < 8; i++) {
        // push into the priority queue the objects of the class car
        pq.push(*(new Car(i, x[i], y[i])));
    }

    for (int i = 0; i < 8; i++) {
        Car temp = pq.top();
        temp.print();
        pq.pop();
    }

    return 0;
}
