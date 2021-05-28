// Program to make a vector class on our own
#include <iostream>
#include<cstring>

using namespace std;

class Vector {
    // Private Attributes
    int *arr;
    int currentSize;
    int maxSize;

public:
    // constructor
    Vector(int defaultSize = 4) {
        maxSize = defaultSize;
        currentSize = 0;
        arr = new int[maxSize];
    }

    // FUNCTIONS

    void operator()(string s) {
        cout << s << "is an awesome Place";
    }

    void push_back(int data) {
        if (currentSize == maxSize) {
            //Doubling Operations
            int *oldArr = arr;
            arr = new int[2 * maxSize];
            maxSize = 2 * maxSize;

            for (int i = 0; i < currentSize; i++) {
                arr[i] = oldArr[i];
            }
            //Delete the oldArr
            delete[] oldArr;
        }
        arr[currentSize] = data;
        currentSize++;
    }

    bool empty() {
        return currentSize == 0;
    }

    int getSize() {
        return currentSize;
    }

    int getMaxSize() {
        return maxSize;
    }

    void pop_back() {
        if (!empty()) {
            currentSize--;
        }
    }

    void print() {
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << ",";
        }
    }

    int at(int i) {
        return arr[i];
    }

    // Operators over user defined [], (), +, * , - , ! etc
    // RETURN BY REFERENCE, so that operations could be performed on them. 
    int& operator[](int i) {
        return arr[i];
    }
};

// Overloading << and >> operators, but need cout and cin which are in header files, hence making the function out of the class
ostream &operator<<(ostream &os, Vector v) {
    cout << "In << operator" << endl;
    v.print();
    return os;
}

istream &operator>>(istream &is, Vector &v) {
    //Input a vector
    return is;
}

int main() {
    // Making the vector
    Vector v(1000);
    Vector fun; //Default Copy Constructors - Shallow Copy

    //Operator () Call
    //Looking like like a function, but it is an object [Functor : Functional Objects]
    //v("Dehradun");
    //fun("Nainital");

    for (int i = 0; i <= 3; i++) {
        v.push_back(i * i);
    }

    fun = v; // Copy Assignment Operators -> Shallow Copy 

    cout << v.getMaxSize() << endl;
    v.push_back(7);
    cout << v.getMaxSize() << endl;
    v.print();

//    For Loop to print the vector 
//    for (int i = 0; i < v.getSize(); i++) {
//          cout<<v[i]<<endl;
//    }
    
    // no need of for loop now since we overloaded the << in line 80 that calls the print method of our vector class
    cout << endl;
    cout << v << fun;

    // since we returned by reference while operator overloading of [], these changes made will be actually visible
    v[2] = 8;
    v[2] /= 6;
    cout << "Final value" << endl;
    cout << v[2];

    return 0;
}
























