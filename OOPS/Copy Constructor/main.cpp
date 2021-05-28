// Program to demonstrate copy constructor
// It exists by default

#include<iostream>

using namespace std;

class Car {
// Private attributes: Can be accessed only by the class itself. By default the attributes are private
private:
    float price;
// Public attributes: Can be accessed outside the class
public:
    string name;
    int modelNo;

    // parameterized constructor
    Car(string n, int model, float p) {
        name = n;
        modelNo = model;
        price = p;
    }

    // COPY CONSTRUCTOR OVERRIDDEN
    Car(Car &temp) {    // REMEMBER TO PASS THE THE OBJECT BY REFERENCE
        cout << "Copy Constructor" << endl;
        name = temp.name;
        modelNo = temp.modelNo;
        price = 500;
    }

    // public methods
    void set_price(float p) {
        price = p;
    }

    void get_data() {
        cout << "Name: " << name << endl;
        cout << "Model: " << modelNo << endl;
        cout << "Price: " << price << endl;
        cout << endl;
    }
};

int main() {
    // object of a car
    Car c("Audi", 1, 10000);  // Other constructor called
    c.get_data();

    // new object
    Car e(c);   // copy constructor - therefore copies the c object to e
    e.get_data();
    
    return 0;
}